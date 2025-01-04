#include "database.h"
#include <QDebug>

// Constructor
Database::Database(const QString &filePath) : m_filePath(filePath) {}

// Authenticate user
bool Database::authenticateUser(const QString &username, const QString &password, QString &role) {
    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not open file for reading.";
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = parseLine(line);

        // Ensure there are exactly three components: username, password, role
        if (details.size() != 3) {
            qDebug() << "Invalid line in database file: " << line;
            continue;
        }

        if (details[0] == username && details[1] == password) {
            role = details[2]; // Extract the user's role
            return true;
        }
    }

    return false; // Authentication failed
}

// Add a new user
bool Database::addUser(const QString &username, const QString &password, const QString &role) {
    QFile file(m_filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Error: Could not open file for writing.";
        return false;
    }

    QTextStream out(&file);
    out << username << "," << password << "," << role << "\n"; // Add user data to file
    return true;
}

// Parse a line from the database file
QStringList Database::parseLine(const QString &line) const {
    return line.split(','); // Split the line by commas
}
