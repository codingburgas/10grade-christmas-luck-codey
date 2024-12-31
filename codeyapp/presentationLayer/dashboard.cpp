#include "dashboard.h"
#include "ui_dashboard.h"
#include "writebook.h"
#include "mybooks.h"
#include <QVBoxLayout>

Dashboard::Dashboard(QWidget *parent)
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
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_2_clicked()
{
    this->hide();

    //Create and show writeBook as a modal dialog
    writeBook writeBook;
    writeBook.setModal(true);
    writeBook.exec();

    this->close();
}


void Dashboard::on_pushButton_clicked()
{
    this->hide();

    //Create and show writeBook as a modal dialog
    writeBook writeBook;
    writeBook.setModal(true);
    writeBook.exec();

    this->close();
}


void Dashboard::on_pushButton_3_clicked()
{
    this->hide();

    //Create and show Dashboard as a modal dialog
    Dashboard Dashboard;
    Dashboard.setModal(true);
    Dashboard.exec();

    this->close();
}


void Dashboard::on_pushButton_4_clicked()
{
    this->hide();

    //Create and show Dashboard as a modal dialog
    myBooks myBooks;
    myBooks.setModal(true);
    myBooks.exec();

    this->close();
}
