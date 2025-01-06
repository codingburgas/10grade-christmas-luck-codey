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

    // Set book details in labels
    ui->label_3->setText(title);
    ui->label_5->setText(author);
    ui->label_6->setText(genre);

    // Connect the rent button
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

    QFile file("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open books file for writing.");
        return;
    }

    QTextStream stream(&file);
    QString updatedContent;
    bool bookFound = false;

    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList details = line.split(",");

        if (details.size() >= 6 && details[0] == bookTitle && details[1] == bookAuthor && details[2] == bookGenre) {
            details[3] = username;                  // Update the renter
            details[5] = QString::number(rentDays); // Update the days left
            bookFound = true;
        }

        updatedContent += details.join(",") + "\n";
    }

    file.resize(0);
    stream << updatedContent;
    file.close();

    if (bookFound) {
        this->daysRented = rentDays; // Store the rental days
        accept();                    // Close the dialog with QDialog::Accepted
    } else {
        QMessageBox::critical(this, "Error", "Book not found in the database.");
    }
}
