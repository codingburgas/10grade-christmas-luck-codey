#include "readbook.h"
#include "ui_readbook.h"
#include "mybooks.h"

readBook::readBook(const QString &bookTitle, const QString &author, const QString &username, const QString &role, const QString &content, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::readBook)
{
    ui->setupUi(this);

    // Set the book details
    ui->label_2->setText(bookTitle);     // Title
    ui->label_3->setText(author);        // Author
    ui->label_7->setText(username);      // Username
    ui->label_8->setText(role);          // Role
    ui->label->setText(content); // Content displayed in a text browser widget

    // Connect the return button
    connect(ui->pushButton, &QPushButton::clicked, this, &readBook::on_pushButton_clicked);
}

readBook::~readBook()
{
    delete ui;
}

void readBook::on_pushButton_clicked()
{
    this->close();

    // Return to the myBooks window
    myBooks myBooksWindow(ui->label_7->text(), ui->label_8->text(), nullptr);
    myBooksWindow.setModal(true);
    myBooksWindow.exec();
}
