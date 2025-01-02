#include "mybooks.h"
#include "ui_mybooks.h"
#include "dashboard.h"

myBooks::myBooks(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::myBooks)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    QPixmap writeIcon(":/assets/images/writeIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);
}

myBooks::~myBooks()
{
    delete ui;
}

void myBooks::on_pushButton_clicked()
{
    this->hide();

    //Create and show myBooks as a modal dialog
    myBooks myBooks;
    myBooks.setModal(true);
    myBooks.exec();

    this->close();
}


void myBooks::on_pushButton_3_clicked()
{
    this->hide();

    //Create and show Dashboard as a modal dialog
    Dashboard Dashboard;
    Dashboard.setModal(true);
    Dashboard.exec();

    this->close();
}

