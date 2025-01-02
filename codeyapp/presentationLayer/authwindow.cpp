#include "authwindow.h"
#include "../dataAccessLayer/dbConnection.h"
#include <QMessageBox>

AuthWindow::AuthWindow(QWidget *parent) : QDialog(parent) {}  // Change QWidget to QDialog

AuthWindow::~AuthWindow() = default;  // Default destructor implementation

// Function to log in a user
bool AuthWindow::loginUser(const QString &username, const QString &password, QString &role) {
    try {
        // Convert QString to std::string
        std::string uname = username.toStdString();
        std::string pass = password.toStdString();
        std::string roleStr;

        // Query the database using the DbConnection class
        if (DbConnection::loginUser(uname, pass, roleStr)) {
            role = QString::fromStdString(roleStr);
            return true; // Login successful
        } else {
            QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
            return false; // Login failed
        }
    } catch (std::exception &e) {
        QMessageBox::critical(this, "Error", e.what());
        return false;
    }
}
