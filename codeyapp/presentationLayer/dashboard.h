#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "dataAccessLayer/database.h"
#include <QStandardItemModel> // For table data

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    Dashboard(const QString &username, const QString &role, QWidget *parent = nullptr); // Overloaded constructor
    ~Dashboard();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void addBookToTable(const QString &title, const QString &author, const QString &genre, const QString &status); // Declare this function

private:
    Ui::Dashboard *ui;
    QStandardItemModel *booksModel; // Model for storing book data
    void loadBooks(); // Function to load books from the file
};

#endif // DASHBOARD_H
