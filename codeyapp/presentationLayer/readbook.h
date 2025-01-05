#ifndef READBOOK_H
#define READBOOK_H

#include <QDialog>

namespace Ui {
class readBook;
}

class readBook : public QDialog
{
    Q_OBJECT

public:
    explicit readBook(const QString &title, const QString &author, const QString &username, const QString &role, const QString &content, QWidget *parent = nullptr);
    ~readBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::readBook *ui;
};

#endif
