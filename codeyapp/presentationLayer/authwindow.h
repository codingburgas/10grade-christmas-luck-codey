#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>

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
    void on_loginButton_clicked(); // This must match exactly with the definition

private:
    Ui::authWindow *ui;
};

#endif // AUTHWINDOW_H
