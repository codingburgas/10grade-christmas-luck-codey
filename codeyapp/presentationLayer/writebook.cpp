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

// Implementation of the virtual function
void writeBook::someFunction()
{
    // Add your logic here (leave it empty if not needed yet)
}

void writeBook::on_cancelButton_clicked()
{
    this->hide();

    // Create and show Dashboard as a modal dialog
    Dashboard dashboard;
    dashboard.setModal(true);
    dashboard.exec();

    this->close();
}
