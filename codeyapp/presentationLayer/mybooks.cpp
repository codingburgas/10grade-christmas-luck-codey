#include "mybooks.h"
#include "ui_mybooks.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include "readbook.h"
#include <QDate>

myBooks::myBooks(const QString &username, const QString &role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myBooks)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);

    ui->label_7->setText(username);
    ui->label_8->setText(role);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Action"});

    loadRentedBooks(username);
    loadUserFunds(username);
}

myBooks::~myBooks()
{
    delete ui;
}


void myBooks::returnBook(const QString &title, const QString &author, const QString &genre, int row)
{
    QFile bookFile("../../dataAccessLayer/books.txt");
    if (!bookFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books.txt for updating.");
        return;
    }

    QTextStream bookStream(&bookFile);
    QString updatedBookContent;
    bool bookReturned = false;
    bool isOverdue = false;

    while (!bookStream.atEnd()) {
        QString line = bookStream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 7 && details[0] == title && details[1] == author && details[2] == genre) {
            int daysLeft = details[5].toInt();
            if (daysLeft <= 0) {
                isOverdue = true;
            }
            details[3] = "Available";
            details[5] = "0";
            bookReturned = true;
        }

        updatedBookContent += details.join(",") + "\n";
    }

    bookFile.resize(0);
    QTextStream bookOut(&bookFile);
    bookOut << updatedBookContent;
    bookFile.close();

    if (bookReturned) {
        if (isOverdue) {
            QFile userFile("../../dataAccessLayer/users.txt");
            if (!userFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
                QMessageBox::critical(this, "Error", "Could not open users.txt for updating.");
                return;
            }

            QTextStream userStream(&userFile);
            QString updatedUserContent;

            while (!userStream.atEnd()) {
                QString line = userStream.readLine();
                QStringList details = line.split(",");

                if (details.size() >= 4 && details[0] == ui->label_7->text()) {
                    double userFunds = details[3].toDouble();
                    if (userFunds >= 25) {
                        userFunds -= 25;
                        QMessageBox::warning(this, "Overdue Fine", "You have been fined 25 BGN for overdue return.");
                    } else {
                        QMessageBox::warning(this, "Insufficient Funds", "You do not have enough funds to pay the overdue fine.");
                    }
                    details[3] = QString::number(userFunds, 'f', 2);
                }

                updatedUserContent += details.join(",") + "\n";
            }

            userFile.resize(0);
            QTextStream userOut(&userFile);
            userOut << updatedUserContent;
            userFile.close();
        }

        QMessageBox::information(this, "Success", "Book returned successfully!");
        ui->tableWidget->removeRow(row);
    } else {
        QMessageBox::critical(this, "Error", "Could not find the book to return.");
    }
}

void myBooks::loadRentedBooks(const QString &username)
{
    QFile file("../../dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books.txt for reading.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 5 && details[3] == username) {
            int currentRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRow);

            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(details[0]));
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(details[1]));
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(details[2]));

            QPushButton *readButton = new QPushButton("Read", this);
            connect(readButton, &QPushButton::clicked, [this, details]() {
                class readBook readBookWindow(details[0], details[1], ui->label_7->text(), ui->label_8->text(), details[4], this);
                readBookWindow.exec();
            });

            QPushButton *returnButton = new QPushButton("Return", this);
            connect(returnButton, &QPushButton::clicked, [this, details, currentRow]() {
                returnBook(details[0], details[1], details[2], currentRow);
            });

            QWidget *buttonWidget = new QWidget(this);
            QHBoxLayout *layout = new QHBoxLayout(buttonWidget);
            layout->addWidget(readButton);
            layout->addWidget(returnButton);
            layout->setContentsMargins(0, 0, 0, 0);
            buttonWidget->setLayout(layout);

            ui->tableWidget->setCellWidget(currentRow, 3, buttonWidget);
        }
    }

    file.close();
}

void myBooks::loadUserFunds(const QString &username)
{
    QFile file("../../dataAccessLayer/users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open users.txt for reading.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 4 && details[0] == username) {
            ui->label_5->setText(QString("%1 BGN").arg(details[3]));
            break;
        }
    }

    file.close();
}

void myBooks::on_pushButton_3_clicked()
{
    this->close();
    Dashboard dashboard(ui->label_7->text(), ui->label_8->text(), nullptr);
    dashboard.exec();
}

void myBooks::recursiveSearch(int row, const QString &searchText)
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

void myBooks::on_searchButton_clicked()
{
    QString searchText = ui->searchBar->text();
    recursiveSearch(0, searchText);
}
