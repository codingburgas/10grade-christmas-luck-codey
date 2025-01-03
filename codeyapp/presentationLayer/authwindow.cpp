#include "authwindow.h"
#include "ui_authwindow.h"
#include "../dataAccessLayer/dbConnection.h"
#include <QMessageBox>

AuthWindow::AuthWindow(QWidget *parent) : QDialog(parent) {}  // Change QWidget to QDialog

AuthWindow::~AuthWindow() = default;
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

// Slot for the login button
void AuthWindow::on_loginButton_clicked()
{
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both username and password.");
        return;
    }

    accept(); // Close dialog and return QDialog::Accepted
}

// Slot for the cancel button
void AuthWindow::on_cancelButton_clicked()
{
    reject(); // Close dialog and return QDialog::Rejected
}

// Getters for username and password
QString AuthWindow::getUsername() const
{
    return username;
}

QString AuthWindow::getPassword() const
{
    return password;
}
