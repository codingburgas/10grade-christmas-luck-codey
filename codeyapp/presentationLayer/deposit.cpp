#include "deposit.h"
#include "ui_deposit.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Deposit::Deposit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Deposit)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Deposit::onDepositButtonClicked);
}

Deposit::~Deposit()
{
    delete ui;
}

double Deposit::getDepositAmount() const
{
    return ui->lineEdit->text().toDouble();
}

void Deposit::onDepositButtonClicked()
{
    QString depositAmountStr = ui->lineEdit->text();
    if (depositAmountStr.isEmpty() || depositAmountStr.toDouble() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid deposit amount.");
        return;
    }

    double depositAmount = depositAmountStr.toDouble();
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

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 4 && details[0] == qobject_cast<Dashboard *>(parent())->getUsername()) {
            double currentFunds = details[3].toDouble();
            currentFunds += depositAmount;
            details[3] = QString::number(currentFunds, 'f', 2);
            userFound = true;
        }

        updatedContent += details.join(",") + "\n";
    }

    file.resize(0);
    QTextStream out(&file);
    out << updatedContent;
    file.close();

    if (userFound) {
        QMessageBox::information(this, "Success", QString("Deposited $%1 successfully!").arg(depositAmount));
        Dashboard *dashboard = qobject_cast<Dashboard *>(parent());
        if (dashboard) {
            dashboard->loadUserFunds();
        }
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "User not found in the database.");
    }
}
