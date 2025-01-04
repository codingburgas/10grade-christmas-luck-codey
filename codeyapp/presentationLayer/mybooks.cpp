#include "mybooks.h"
#include "ui_mybooks.h"
#include "dashboard.h"

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

    // Set username and role labels
    ui->label_7->setText(username);
    ui->label_8->setText(role);
}

myBooks::~myBooks()
{
    delete ui;
}

void myBooks::on_pushButton_3_clicked()
{
    // Close My Books and open Dashboard with the current username and role
    this->close(); // Close My Books first
    Dashboard dashboard(ui->label_7->text(), ui->label_8->text(), nullptr);
    dashboard.exec();
}
