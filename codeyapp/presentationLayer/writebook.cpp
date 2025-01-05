#include "writebook.h"
#include "ui_writebook.h"
#include "dashboard.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

writeBook::writeBook(const QString &author, const QString &role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::writeBook)
    , currentAuthor(author)
    , currentRole(role)
{
    ui->setupUi(this);

    QPixmap writerImage(":/assets/images/writerImage.png");
    ui->writeImage->setPixmap(writerImage);

    ui->username->setText(author);
    ui->role->setText(role);
}

writeBook::~writeBook()
{
    delete ui;
}

void writeBook::on_cancelButton_clicked()
{
    this->close();
}

void writeBook::on_writeButton_clicked()
{
    QString title = ui->titleInput->text();
    QString genre = ui->genreInput->text();
    QString content = ui->contentInput->text();
    QString status = "Available";

    if (title.isEmpty() || genre.isEmpty() || content.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please fill out all fields.");
        return;
    }

    QFile file("/Users/ani/Documents/School/10grade-christmas-luck-codey/codeyapp/dataAccessLayer/books.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << title << "," << currentAuthor << "," << genre << "," << status << "," << content <<"\n";
        file.close();

        emit bookAdded(title, currentAuthor, genre, status);
        QMessageBox::information(this, "Success", "Book added successfully!");

        this->close();
    } else {
        QMessageBox::critical(this, "Error", "Could not open file for writing.");
    }
}
