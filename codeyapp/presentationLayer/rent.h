#ifndef RENT_H
#define RENT_H

#include <QDialog>

namespace Ui {
class Rent;
}

class Rent : public QDialog
{
    Q_OBJECT

public:
    explicit Rent(const QString &user, const QString &title, const QString &author, const QString &genre, QWidget *parent = nullptr);
    ~Rent();

    int getDaysRented() const;

private slots:
    void onRentButtonClicked(); // Declare the slot for the rent button

private:
    Ui::Rent *ui;
    QString username;
    QString bookTitle; // To store the book title
    QString bookAuthor; // To store the book author
    QString bookGenre; // To store the book genre
    int daysRented;
};

#endif // RENT_H
