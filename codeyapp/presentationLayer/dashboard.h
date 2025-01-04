#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "dataAccessLayer/database.h"
#include <QStandardItemModel>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    Dashboard(const QString &username, const QString &role, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_searchButton_clicked();
    void addBookToTable(const QString &title, const QString &author, const QString &genre, const QString &status);

private:
    Ui::Dashboard *ui;
    QStandardItemModel *booksModel;
    void loadBooks();
};

#endif
