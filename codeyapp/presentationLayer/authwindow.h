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

private:
    Ui::authWindow *ui;
};

#endif // AUTHWINDOW_H
