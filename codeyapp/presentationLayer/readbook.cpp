#include "readbook.h"
#include "ui_readbook.h"
#include "mybooks.h"

readBook::readBook(const QString &bookTitle, const QString &author, const QString &username, const QString &role, const QString &content, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::readBook)
{
    ui->setupUi(this);


    ui->label_2->setText(bookTitle);
    ui->label_3->setText(author);
    ui->label_7->setText(username);
    ui->label_8->setText(role);
    ui->contentInput->setText(content);
    ui->contentInput->setFocus();


    connect(ui->myBooksBTN, &QPushButton::clicked, this, &readBook::on_myBooksBTN_clicked);
}

readBook::~readBook()
{
    delete ui;
}

void readBook::on_myBooksBTN_clicked()
{
    this->close();

    myBooks myBooksWindow(ui->label_7->text(), ui->label_8->text(), nullptr);
    myBooksWindow.setModal(true);
    myBooksWindow.exec();
}
