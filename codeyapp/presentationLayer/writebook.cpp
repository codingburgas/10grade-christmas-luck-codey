#include "writebook.h"
#include "ui_writebook.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

writeBook::writeBook(const QString &author, const QString &role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::writeBook)
    , currentAuthor(author) // Initialize the author
    , currentRole(role)     // Initialize the role
{
    ui->setupUi(this);

    QPixmap writerImage(":/assets/images/writerImage.png");
    ui->writeImage->setPixmap(writerImage);

    // Optionally display the author's name and role in the Write a Book window
    ui->username->setText(author); // Ensure QLabel named "label_username" exists in the UI
    ui->role->setText(role);       // Ensure QLabel named "label_role" exists in the UI
}

writeBook::~writeBook()
{
    delete ui;
}

void writeBook::on_cancelButton_clicked()
{
    this->close(); // Close the current dialog
}

void writeBook::on_writeButton_clicked()
{
    QString title = ui->titleInput->text();
    QString genre = ui->genreInput->text();
    QString content = ui->contentInput->text();
    QString status = "Available"; // Default status for a new book

    if (title.isEmpty() || genre.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill out all fields.");
        return;
    }

    QFile file("dataAccessLayer/books.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << title << "," << currentAuthor << "," << genre << "," << status << "\n"; // Write to file
        file.close();

        // Emit the signal with book data
        emit bookAdded(title, currentAuthor, genre, status);
        QMessageBox::information(this, "Success", "Book added successfully!");

        // Close only the Write a Book dialog
        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Could not open file for writing.");
    }
}
