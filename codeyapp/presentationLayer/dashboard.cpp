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
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::loadBooks()
{
    QFile file("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open books.txt for reading.";
        return;
    }


    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 5) {
            int currentRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRow);

            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(details[0]));
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(details[1]));
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(details[2]));

            QPushButton *statusButton = new QPushButton(this);

            if (details[3] == "Available") {
                statusButton->setText("Rent");
                connect(statusButton, &QPushButton::clicked, [this, details, currentRow]() {
                    rentBook(details[0], details[1], details[2], currentRow);
                });
            } else if (details[3] == ui->label_7->text()) {
                statusButton->setText("Read");
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
    QFile file("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
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
        button->setText("Read");
        button->disconnect();
        connect(button, &QPushButton::clicked, [this, title, author, genre]() {
            // Open the readBook window
            class readBook readBookWindow(title, author, ui->label_7->text(), ui->label_8->text(), genre, this);
            readBookWindow.exec();
        });
    }

    QMessageBox::information(this, "Success", "Book rented successfully!");
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

void Dashboard::on_searchButton_clicked()
{
    QString searchText = ui->searchBar->text();

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *titleItem = ui->tableWidget->item(row, 0);

        if (titleItem && titleItem->text().contains(searchText, Qt::CaseInsensitive)) {
            ui->tableWidget->setRowHidden(row, false);
        } else {
            ui->tableWidget->setRowHidden(row, true);
        }
    }
}

void Dashboard::on_pushButton_5_clicked()
{

    //Create and show Deposit as a modal dialog
    Deposit Deposit;
    Deposit.setModal(true);
    Deposit.exec();

    this->close();
}


void Dashboard::on_pushButton_6_clicked()
{
    //Create and show Withdraw as a modal dialog
    Withdraw Withdraw;
    Withdraw.setModal(true);
    Withdraw.exec();

    this->close();
}

