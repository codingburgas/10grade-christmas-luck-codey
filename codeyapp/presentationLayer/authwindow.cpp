#include "authwindow.h"
#include "ui_authwindow.h"
#include "../dataAccessLayer/login.cpp"
#include <QMessageBox>

authWindow::authWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::authWindow)
{
    ui->setupUi(this);
    initDatabaseAzure();
}

authWindow::~authWindow()
{
    closeDatabase();
    delete ui;
}

void authWindow::on_loginButton_clicked() {
    std::string username = ui->lineEdit->text().toStdString();
    std::string password = ui->lineEdit_2->text().toStdString();
    std::string role;

    if (login(username, password, role)) {
        QMessageBox::information(this, "Success", "Login successful! Role: " + QString::fromStdString(role));
        // Navigate to the appropriate dashboard based on role
    } else {
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    }
}
