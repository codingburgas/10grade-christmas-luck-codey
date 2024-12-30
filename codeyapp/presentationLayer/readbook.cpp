#include "readbook.h"
#include "ui_readbook.h"

readBook::readBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::readBook)
{
    ui->setupUi(this);
}

readBook::~readBook()
{
    delete ui;
}
