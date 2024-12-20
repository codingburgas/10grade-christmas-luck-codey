#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap lampBackground(":/assets/images/topLampBackground.png");
    QPixmap linesBackground(":/assets/images/backgroundLines.png");
    QPixmap backgroundText(":/assets/images/backgroundText.png");
    ui->label_lampBackground->setPixmap(lampBackground);
    ui->label_linesBackground->setPixmap(linesBackground);
    ui->label_backgroundText->setPixmap(backgroundText);
}


MainWindow::~MainWindow()
{
    delete ui;
}
