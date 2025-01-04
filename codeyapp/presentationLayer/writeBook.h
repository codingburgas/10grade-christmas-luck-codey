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
    explicit writeBook(const QString &author, QWidget *parent = nullptr); // Pass the author's name
    ~writeBook();

signals:
    void bookAdded(const QString &title, const QString &author, const QString &genre, const QString &status); // Signal to send book data

private slots:
    void on_cancelButton_clicked();
    void on_writeButton_clicked(); // Slot for the "Write a book" button

private:
    Ui::writeBook *ui;
    QString currentAuthor; // Store the current author's name
};

#endif // WRITEBOOK_H
