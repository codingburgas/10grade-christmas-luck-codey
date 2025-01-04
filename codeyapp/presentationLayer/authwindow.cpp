#include "authwindow.h"
#include "ui_authwindow.h"
#include "dataAccessLayer/database.h"
#include "dashboard.h"
#include <QMessageBox>

authWindow::authWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::authWindow)
    , db(new Database("dataAccessLayer/users.txt"))
{
    ui->setupUi(this);
}

authWindow::~authWindow()
{
    delete ui;
    delete db;
}

void authWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString role = ui->comboBox->currentText();

    QFile file("dataAccessLayer/users.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        bool usernameExists = false;
        bool credentialsMatch = false;

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList details = line.split(",");

            if (details.size() == 3) {
                if (details[0] == username) {
                    usernameExists = true;

                    if (details[1] == password && details[2] == role) {
                        credentialsMatch = true;
                        break;
                    }
                }
            }
        }

        file.close();

        if (credentialsMatch) {
            this->hide();
            Dashboard dashboard(username, role);
            dashboard.setModal(true);
            dashboard.exec();
            this->close();

        } else if (usernameExists) {
            QMessageBox::warning(this, "Login Failed", "Incorrect password or role. Please try again.");

        } else {
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << username << "," << password << "," << role << "\n";
                file.close();

                QMessageBox::information(this, "Account Created", "New account created. Proceeding to dashboard.");
                this->hide();
                Dashboard dashboard(username, role);
                dashboard.setModal(true);
                dashboard.exec();
                this->close();
            } else {
                QMessageBox::critical(this, "Error", "Failed to create a new account. Please try again.");
            }
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the user database file.");
    }
}


