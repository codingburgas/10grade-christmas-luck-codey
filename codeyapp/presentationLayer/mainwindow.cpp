#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authwindow.h"
#include "dashboard.h"
#include "writebook.h"
#include "readbook.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set background images
    QPixmap lampBackground(":/assets/images/topLampBackground.png");
    QPixmap linesBackground(":/assets/images/backgroundLines.png");
    QPixmap backgroundText(":/assets/images/backgroundText.png");
    ui->label_lampBackground->setPixmap(lampBackground);
    ui->label_linesBackground->setPixmap(linesBackground);
    ui->label_backgroundText->setPixmap(backgroundText);

    // Show login dialog
    AuthWindow authWindow;
    QString role;

    // Display the login window and wait for user input
    if (authWindow.exec() == QDialog::Accepted) {
        QString username = authWindow.getUsername();
        QString password = authWindow.getPassword();

        // Attempt login with username and password
        if (authWindow.loginUser(username, password, role)) {
            if (role == "writer") {
                Dashboard *writerDashboard = new Dashboard(this);
                writerDashboard->show();
            } else if (role == "reader") {
                readBook *readerWindow = new readBook(this);
                readerWindow->show();
            }
        } else {
            QMessageBox::critical(this, "Login Failed", "You cannot access the application.");
        }
    } else {
        QMessageBox::critical(this, "Login Failed", "Login was canceled.");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();

    // Create and show authWindow as a modal dialog
    AuthWindow authWindow;
    authWindow.setModal(true);
    authWindow.exec();

    this->close();
}
