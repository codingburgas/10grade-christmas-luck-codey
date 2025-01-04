#include "authwindow.h"
#include "ui_authwindow.h"
#include "dataAccessLayer/database.h"
#include <QMessageBox>

authWindow::authWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::authWindow)
    , db(new Database("dataAccessLayer/users.txt")) // Initialize the Database
{
    ui->setupUi(this);
}

authWindow::~authWindow()
{
    delete ui;
    delete db; // Clean up the Database instance
}

// Join button functionality (Login)
void authWindow::on_joinButton_clicked()
{
    QString username = ui->lineEdit->text(); // Ensure usernameLineEdit exists in UI
    QString password = ui->lineEdit_2->text(); // Ensure passwordLineEdit exists in UI
    QString role;

    if (db->authenticateUser(username, password, role)) {
        QMessageBox::information(this, "Login Successful", "Welcome, " + role + "!");
        // Proceed to the next screen or functionality
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
