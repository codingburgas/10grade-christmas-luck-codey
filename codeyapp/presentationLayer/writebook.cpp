#include "writebook.h"
#include "ui_writebook.h"
#include "dashboard.h"

writeBook::writeBook(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::writeBook)
{
    ui->setupUi(this);

    QPixmap writerImage(":/assets/images/writerImage.png");
    ui->writeImage->setPixmap(writerImage);
}

writeBook::~writeBook()
{
    delete ui;
}

void writeBook::on_cancelButton_clicked()
{
    this->hide();

    //Create and show authWindow as a modal dialog
    Dashboard Dashboard;
    Dashboard.setModal(true);
    Dashboard.exec();

    this->close();
}

