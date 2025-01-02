#ifndef MYBOOKS_H
#define MYBOOKS_H

#include <QDialog>

namespace Ui {
class myBooks;
}

class myBooks : public QDialog
{
    Q_OBJECT

public:
    explicit myBooks(QWidget *parent = nullptr);
    ~myBooks();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::myBooks *ui;
};

#endif // MYBOOKS_H
