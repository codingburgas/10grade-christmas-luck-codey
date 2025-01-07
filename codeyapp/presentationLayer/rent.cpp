#include "rent.h"
#include "ui_rent.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "dashboard.h"

Rent::Rent(const QString &user, const QString &title, const QString &author, const QString &genre, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Rent)
    , username(user)
    , bookTitle(title)
    , bookAuthor(author)
    , bookGenre(genre)
{
    ui->setupUi(this);

    ui->label_3->setText(title);
    ui->label_5->setText(author);
    ui->label_6->setText(genre);

    connect(ui->pushButton, &QPushButton::clicked, this, &Rent::onRentButtonClicked);
}

Rent::~Rent()
{
    delete ui;
}

int Rent::getDaysRented() const {
    return ui->lineEdit->text().toInt();
}

void Rent::onRentButtonClicked()
{
    QString rentDaysStr = ui->lineEdit->text();
    if (rentDaysStr.isEmpty() || rentDaysStr.toInt() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number of days.");
        return;
    }

    int rentDays = rentDaysStr.toInt();

    double bookPrice = 0.0;
    QFile bookFile("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (!bookFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books file for reading.");
        return;
    }

    QTextStream bookStream(&bookFile);
    bool bookFound = false;

    while (!bookStream.atEnd()) {
        QString line = bookStream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 7 && details[0] == bookTitle && details[1] == bookAuthor && details[2] == bookGenre) {
            bookPrice = details[6].toDouble();
            bookFound = true;
            break;
        }
    }
    bookFile.close();

    if (!bookFound) {
        QMessageBox::critical(this, "Error", "Book not found in the database.");
        return;
    }


    QFile userFile("../../../../../dataAccessLayer/users.txt");
    if (!userFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open users file for updating.");
        return;
    }

    QTextStream userStream(&userFile);
    QString updatedUserContent;
    bool sufficientFunds = false;

    while (!userStream.atEnd()) {
        QString line = userStream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 4 && details[0] == username && !sufficientFunds) {
            double userFunds = details[3].toDouble();

            if (userFunds >= bookPrice) {
                userFunds -= bookPrice;
                details[3] = QString::number(userFunds);
                sufficientFunds = true;
            } else {
                QMessageBox::warning(this, "Insufficient Funds", "You do not have enough funds to rent this book.");
                userFile.close();
                return;
            }
        }
        updatedUserContent += details.join(",") + "\n";
    }

    userFile.resize(0);
    QTextStream userOut(&userFile);
    userOut << updatedUserContent;
    userFile.close();

    if (sufficientFunds) {

        if (!bookFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Could not open books file for updating.");
            return;
        }

        QTextStream bookStream(&bookFile);
        QString updatedBookContent;

        while (!bookStream.atEnd()) {
            QString line = bookStream.readLine();
            QStringList details = line.split(",");

            if (details.size() >= 7 && details[0] == bookTitle && details[1] == bookAuthor && details[2] == bookGenre) {
                details[3] = username;
                details[5] = QString::number(rentDays);
            }
            updatedBookContent += details.join(",") + "\n";
        }

        bookFile.resize(0);
        QTextStream bookOut(&bookFile);
        bookOut << updatedBookContent;
        bookFile.close();

        QMessageBox::information(this, "Success", "Book rented successfully!");
        accept();
    }
}
