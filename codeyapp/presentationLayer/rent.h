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
    void onRentButtonClicked();

private:
    Ui::Rent *ui;
    QString username;
    QString bookTitle;
    QString bookAuthor;
    QString bookGenre;
    int daysRented;
};

#endif
