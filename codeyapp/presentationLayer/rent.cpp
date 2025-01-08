#include "rent.h"
#include "ui_rent.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "dashboard.h"
#include <QDate>

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

void Rent::onRentButtonClicked() {
    QString rentDaysStr = ui->lineEdit->text();
    if (rentDaysStr.isEmpty() || rentDaysStr.toInt() <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number of days.");
        return;
    }

    int rentDays = rentDaysStr.toInt();
    double bookPrice = 0.0;
    QString author;

    #ifdef __APPLE__
        QFile bookFile("../../../../../dataAccessLayer/books.txt");
    #elif _WIN64
        QFile bookFile("../../dataAccessLayer/books.txt");
    #else
    #error "Unsupported platform"
    #endif

    if (!bookFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books file for updating.");
        return;
    }

    QTextStream bookStream(&bookFile);
    QString updatedBookContent;
    bool bookFound = false;

    while (!bookStream.atEnd()) {
        QString line = bookStream.readLine();
        QStringList details = line.split(",");


        if (details.size() == 7) {
            if (details[0] == bookTitle && details[1] == bookAuthor && details[2] == bookGenre) {
                bookPrice = details[6].toDouble();
                author = details[1];
                details[3] = username;
                details[5] = QString::number(rentDays);
                details.append(QDate::currentDate().toString("yyyy-MM-dd"));
                bookFound = true;
            }
            updatedBookContent += details.join(",") + "\n";
        } else {
            updatedBookContent += line + "\n";
        }
    }

    bookFile.resize(0);
    QTextStream bookOut(&bookFile);
    bookOut << updatedBookContent;
    bookFile.close();

    if (!bookFound) {
        QMessageBox::critical(this, "Error", "Book not found in the database.");
        return;
    }

    #ifdef __APPLE__
        QFile userFile("../../../../../dataAccessLayer/users.txt");
    #elif _WIN64
        QFile userFile("../../dataAccessLayer/users.txt");
    #else
    #error "Unsupported platform"
    #endif

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
        if (!userFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Could not open users file for updating.");
            return;
        }

        userStream.setDevice(&userFile);
        updatedUserContent.clear();

        while (!userStream.atEnd()) {
            QString line = userStream.readLine();
            QStringList details = line.split(",");

            if (details.size() >= 4 && details[0] == author) {
                double authorFunds = details[3].toDouble();
                authorFunds += bookPrice;
                details[3] = QString::number(authorFunds);
            }
            updatedUserContent += details.join(",") + "\n";
        }

        userFile.resize(0);
        userOut.setDevice(&userFile);
        userOut << updatedUserContent;
        userFile.close();

        accept();
    }
}
