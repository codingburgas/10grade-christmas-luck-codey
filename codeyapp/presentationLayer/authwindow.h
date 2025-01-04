#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include "dataAccessLayer/database.h"

namespace Ui {
class authWindow;
}

class authWindow : public QDialog
{
    Q_OBJECT

public:
    explicit authWindow(QWidget *parent = nullptr);
    ~authWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::authWindow *ui;
    Database *db; // Added Database instance
};

#endif // AUTHWINDOW_H
