#ifndef MYBOOKS_H
#define MYBOOKS_H

#include <QDialog>

class readBook;

namespace Ui {
class myBooks;
}

class myBooks : public QDialog
{
    Q_OBJECT

public:
    explicit myBooks(const QString &username, const QString &role, QWidget *parent = nullptr);
    ~myBooks();

private slots:
    void on_pushButton_3_clicked();
    void on_searchButton_clicked();

private:
    Ui::myBooks *ui;

    void loadRentedBooks(const QString &username);
    void loadUserFunds(const QString &username);
    void recursiveSearch(int row, const QString &searchText);
};

#endif
