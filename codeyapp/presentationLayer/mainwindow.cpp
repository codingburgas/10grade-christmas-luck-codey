#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authwindow.h"
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

void MainWindow::on_pushButton_clicked()
{
    // Hide MainWindow before opening authWindow
    this->hide();

    // Create and show authWindow as a modal dialog
    authWindow authWindow;
    authWindow.setModal(true);  // Make it modal (blocks interaction with MainWindow)
    authWindow.exec();

    // After authWindow is closed, show MainWindow again (optional)
    this->close();  // This can be omitted if you don't need to show MainWindow again
}
