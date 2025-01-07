#include "dashboard.h"
#include "deposit.h"
#include "withdraw.h"
#include "ui_dashboard.h"
#include "writebook.h"
#include "mybooks.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include <readbook.h>
#include <rent.h>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    QPixmap writeIcon(":/assets/images/writeIcon.png");
    QPixmap depositIcon(":/assets/images/depositIcon.png");
    QPixmap withdrawIcon(":/assets/images/withdrawIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);
    ui->label_write->setPixmap(writeIcon);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});


    connect(ui->searchButton, &QPushButton::clicked, this, &Dashboard::on_searchButton_clicked);

    loadBooks();
}

Dashboard::Dashboard(const QString &username, const QString &role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    QPixmap writeIcon(":/assets/images/writeIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);
    ui->label_write->setPixmap(writeIcon);

    ui->label_7->setText(username);
    ui->label_8->setText(role);

    if (role.toLower() == "reader") {
        ui->pushButton_2->hide();
        ui->pushButton->hide();
        ui->label_write->hide();
        ui->label_5->hide();
    }

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});

    loadBooks();
    loadUserFunds();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::loadUserFunds()
{
    QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open users.txt for reading.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 4 && details[0] == ui->label_7->text()) {
            ui->label_funds->setText(QString("Funds: $%1").arg(details[3]));
            break;
        }
    }

    file.close();
}

QString Dashboard::getUsername() const {
    return ui->label_7->text();
}

void Dashboard::updateBookDetails(const QString &title, const QString &author, const QString &genre, const QString &renter, int daysLeft)
{
    QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books.txt for writing.");
        return;
    }

    QTextStream in(&file);
    QString updatedContent;
    bool bookFound = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 6 && details[0] == title && details[1] == author && details[2] == genre) {
            details[3] = renter;
            details[5] = QString::number(daysLeft);
            bookFound = true;
        }

        updatedContent += details.join(",") + "\n";
    }

    file.resize(0);
    QTextStream out(&file);
    out << updatedContent;
    file.close();

    if (bookFound) {
        QMessageBox::information(this, "Success", QString("The book has been successfully rented for %1 days!").arg(daysLeft));
    } else {
        QMessageBox::critical(this, "Error", "Could not find the book in the database to update.");
    }
}

void Dashboard::loadBooks()
{
    QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open books.txt for reading.";
        return;
    }

    QTextStream in(&file);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status", "Price"});

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 7) {
            int currentRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRow);

            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(details[0]));
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(details[1]));
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(details[2]));
            ui->tableWidget->setItem(currentRow, 4, new QTableWidgetItem(details[6]));

            QPushButton *statusButton = new QPushButton(this);

            if (details[3] == "Available") {
                statusButton->setText("Rent");

                connect(statusButton, &QPushButton::clicked, [this, details]() {

                    Rent rentDialog(ui->label_7->text(), details[0], details[1], details[2], this);
                    if (rentDialog.exec() == QDialog::Accepted) {

                        int daysRented = rentDialog.getDaysRented();
                        updateBookDetails(details[0], details[1], details[2], ui->label_7->text(), daysRented);
                    }
                });
            } else if (details[3] == ui->label_7->text()) {

                int daysLeft = details[5].toInt();
                statusButton->setText(QString("Read, %1 days left").arg(daysLeft));
                connect(statusButton, &QPushButton::clicked, [this, details]() {
                    class readBook readBookWindow(details[0], details[1], ui->label_7->text(), ui->label_8->text(), details[4], this);
                    readBookWindow.exec();
                });
            } else {

                statusButton->setText("Unavailable");
                statusButton->setDisabled(true);
            }

            ui->tableWidget->setCellWidget(currentRow, 3, statusButton);
        }
    }

    file.close();
}


void Dashboard::rentBook(const QString &title, const QString &author, const QString &genre, int row)
{

    Rent rentDialog(ui->label_7->text(), title, author, genre, this);
    if (rentDialog.exec() == QDialog::Accepted) {

        int daysRented = rentDialog.getDaysRented();

        QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Could not open books.txt for writing.");
            return;
        }

        QTextStream in(&file);
        QString updatedContent;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList details = line.split(",");

            if (details[0] == title && details[1] == author && details[2] == genre) {

                details[3] = ui->label_7->text();
                if (details.size() >= 6) {
                    details[5] = QString::number(daysRented);
                } else {
                    details.append(QString::number(daysRented));
                }
                updatedContent += details.join(",") + "\n";
            } else {
                updatedContent += line + "\n";
            }
        }

        file.resize(0);
        QTextStream out(&file);
        out << updatedContent;
        file.close();

        QPushButton *button = qobject_cast<QPushButton *>(ui->tableWidget->cellWidget(row, 3));
        if (button) {
            button->setText(QString("Read, %1 days left").arg(daysRented));
            button->disconnect();
            connect(button, &QPushButton::clicked, [this, title, author, genre]() {
                class readBook readBookWindow(title, author, ui->label_7->text(), ui->label_8->text(), genre, this);
                readBookWindow.exec();
            });
        }

        QMessageBox::information(this, "Success", QString("You have rented the book for %1 days!").arg(daysRented));
    }
}

void Dashboard::readBook(const QString &title, const QString &genre)
{
    QMessageBox::information(this, "Reading Book", "You are now reading: " + title + " (" + genre + ")");
}

void Dashboard::on_pushButton_2_clicked()
{
    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this);
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable);
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_clicked()
{
    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this);
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable);
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_3_clicked()
{
    this->hide();
    Dashboard dashboard(ui->label_7->text(), ui->label_8->text(), nullptr);
    dashboard.setModal(true);
    dashboard.exec();
    this->close();
}

void Dashboard::on_pushButton_4_clicked()
{
    this->close();
    myBooks myBooks(ui->label_7->text(), ui->label_8->text(), nullptr);
    myBooks.exec();
}

void Dashboard::addBookToTable(const QString &title, const QString &author, const QString &genre, const QString &status)
{
    int currentRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRow);

    ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(title));
    ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(author));
    ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(genre));

    QPushButton *statusButton = new QPushButton(this);
    if (status == "Available") {
        statusButton->setText("Rent");
        connect(statusButton, &QPushButton::clicked, [this, title, author, genre, currentRow]() {
            rentBook(title, author, genre, currentRow);
        });
    } else if (status == ui->label_7->text()) {
        statusButton->setText("Read");
        connect(statusButton, &QPushButton::clicked, [this, title, genre]() {
            readBook(title, genre);
        });
    } else {
        statusButton->setText("Unavailable");
        statusButton->setDisabled(true);
    }

    ui->tableWidget->setCellWidget(currentRow, 3, statusButton);
}

void Dashboard::recursiveSearch(int row, const QString &searchText)
{
    if (row >= ui->tableWidget->rowCount()) {
        return;
    }

    QTableWidgetItem *titleItem = ui->tableWidget->item(row, 0);
    if (titleItem && titleItem->text().contains(searchText, Qt::CaseInsensitive)) {
        ui->tableWidget->setRowHidden(row, false);
    } else {
        ui->tableWidget->setRowHidden(row, true);
    }

    recursiveSearch(row + 1, searchText);
}

void Dashboard::on_searchButton_clicked()
{
    QString searchText = ui->searchBar->text();
    recursiveSearch(0, searchText);
}

void Dashboard::on_pushButton_5_clicked()
{
    Deposit depositDialog(this);
    if (depositDialog.exec() == QDialog::Accepted) {
        QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/users.txt");
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QString updatedContent;
            QTextStream in(&file);

            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList details = line.split(",");

                if (details.size() >= 4 && details[0] == ui->label_7->text()) {

                    double currentFunds = details[3].toDouble();
                    double depositAmount = depositDialog.getDepositAmount();
                    currentFunds += depositAmount;

                    details[3] = QString::number(currentFunds, 'f', 2);
                }

                updatedContent += details.join(",") + "\n";
            }

            file.resize(0);
            QTextStream out(&file);
            out << updatedContent;
            file.close();

            QMessageBox::information(this, "Success", QString("Deposited $%1 successfully!").arg(depositDialog.getDepositAmount()));

            loadUserFunds();
        } else {
            QMessageBox::critical(this, "Error", "Could not open users.txt for writing.");
        }
    }
}

void Dashboard::on_pushButton_6_clicked()
{
    Withdraw withdrawDialog(this);
    if (withdrawDialog.exec() == QDialog::Accepted) {
        QFile file("E:/Mariq/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/users.txt");
        if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QString updatedContent;
            QTextStream in(&file);

            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList details = line.split(",");

                if (details.size() >= 4 && details[0] == ui->label_7->text()) {

                    double currentFunds = details[3].toDouble();
                    double withdrawAmount = withdrawDialog.getWithdrawAmount();

                    if (withdrawAmount > currentFunds) {
                        QMessageBox::warning(this, "Insufficient Funds", "You don't have enough funds to withdraw this amount.");
                        return;
                    }

                    currentFunds -= withdrawAmount;

                    details[3] = QString::number(currentFunds, 'f', 2);
                }

                updatedContent += details.join(",") + "\n";
            }

            file.resize(0);
            QTextStream out(&file);
            out << updatedContent;
            file.close();

            QMessageBox::information(this, "Success", QString("Withdrew $%1 successfully!").arg(withdrawDialog.getWithdrawAmount()));

            loadUserFunds();
        } else {
            QMessageBox::critical(this, "Error", "Could not open users.txt for writing.");
        }
    }
}

