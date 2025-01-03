#ifndef WRITEBOOK_H
#define WRITEBOOK_H

#include <QDialog>

namespace Ui {
class writeBook;
}

class writeBook : public QDialog
{
    Q_OBJECT

public:
    explicit writeBook(QWidget *parent = nullptr);
    ~writeBook();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::writeBook *ui;
};

#endif // WRITEBOOK_H
