#include "mybooks.h"
#include "ui_mybooks.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
#include "readbook.h"

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
}

myBooks::~myBooks()
{
    delete ui;
}

void myBooks::loadRentedBooks(const QString &username)
{
    QFile file("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
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
            ui->tableWidget->setCellWidget(currentRow, 3, readButton);
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
