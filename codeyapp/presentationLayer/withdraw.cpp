#include "withdraw.h"
#include "ui_withdraw.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

Withdraw::Withdraw(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Withdraw)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Withdraw::onWithdrawButtonClicked);
}

Withdraw::~Withdraw()
{
    delete ui;
}

double Withdraw::getWithdrawAmount() const
{
    return ui->lineEdit->text().toDouble();
}

void Withdraw::onWithdrawButtonClicked()
{
    QString withdrawAmountStr = ui->lineEdit->text();
    if (withdrawAmountStr.isEmpty() || withdrawAmountStr.toDouble() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid withdrawal amount.");
        return;
    }

    double withdrawAmount = withdrawAmountStr.toDouble();
    #ifdef __APPLE__
        QFile file("../../../../../dataAccessLayer/users.txt");
    #elif _WIN64
        QFile file("../../dataAccessLayer/users.txt");
    #else
    #error "Unsupported platform"
    #endif
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open users.txt for writing.");
        return;
    }

    QTextStream stream(&file);
    QString updatedContent;
    bool userFound = false;

    Dashboard *dashboard = qobject_cast<Dashboard *>(parent());
    if (!dashboard) {
        QMessageBox::critical(this, "Error", "Dashboard not found. Unable to complete withdrawal.");
        file.close();
        return;
    }

    QString username = dashboard->getUsername();

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 4 && details[0] == username) {
            double currentFunds = details[3].toDouble();

            if (currentFunds >= withdrawAmount) {
                currentFunds -= withdrawAmount;
                details[3] = QString::number(currentFunds, 'f', 2);
                userFound = true;
            } else {
                QMessageBox::warning(this, "Insufficient Funds", "You do not have enough funds for this withdrawal.");
                file.close();
                return;
            }

            updatedContent += details.join(",") + "\n";
            break;
        } else {

            updatedContent += line + "\n";
        }
    }

    file.resize(0);
    QTextStream out(&file);
    out << updatedContent;
    file.close();

    if (userFound) {
        QMessageBox::information(this, "Success", QString("Withdrew $%1 successfully!").arg(withdrawAmount));
        if (dashboard) {
            dashboard->loadUserFunds();
        }
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "User not found in the database.");
    }
}
