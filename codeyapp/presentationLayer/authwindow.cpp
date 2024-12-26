#include "authwindow.h"
#include "ui_authwindow.h"

authWindow::authWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::authWindow)
{
    ui->setupUi(this);
}

authWindow::~authWindow()
{
    delete ui;
}
