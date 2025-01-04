#include "dashboard.h"
#include "ui_dashboard.h"
#include "writebook.h"
#include "mybooks.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    QPixmap writeIcon(":/assets/images/writeIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);
    ui->label_write->setPixmap(writeIcon);

    // Set up tableWidget headers
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});

    // Load books from the file
    loadBooks();
}

// Overloaded constructor to accept username and role
Dashboard::Dashboard(const QString &username, const QString &role, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    QPixmap logo(":/assets/images/logo.png");
    QPixmap libraryIcon(":/assets/images/libraryIcon.png");
    QPixmap booksIcon(":/assets/images/booksIcon.png");
    QPixmap writeIcon(":/assets/images/writeIcon.png");
    ui->label_logo->setPixmap(logo);
    ui->label_libraryIcon->setPixmap(libraryIcon);
    ui->label_books->setPixmap(booksIcon);
    ui->label_write->setPixmap(writeIcon);

    // Set username and role labels
    ui->label_7->setText(username);
    ui->label_8->setText(role);

    // Set up tableWidget headers
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});

    // Load books from the file
    loadBooks();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::loadBooks()
{
    QFile file("dataAccessLayer/books.txt"); // File containing book data
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open books.txt for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() == 4) { // Ensure the line has exactly 4 fields
            int currentRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRow);

            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(details[0])); // Title
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(details[1])); // Author
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(details[2])); // Genre
            ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(details[3])); // Status
        }
    }

    file.close();
}

void Dashboard::on_pushButton_2_clicked()
{
    // Open the "Write a Book" dialog with the current username and role
    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this); // Pass username (author) and role
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable); // Connect the signal to update the table
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_clicked()
{
    // Open the "Write a Book" dialog with the current username and role
    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this); // Pass username (author) and role
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable); // Connect the signal to update the table
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_3_clicked()
{
    this->hide();

    // Create and show Dashboard as a modal dialog
    Dashboard Dashboard;
    Dashboard.setModal(true);
    Dashboard.exec();

    this->close();
}

void Dashboard::on_pushButton_4_clicked()
{
    // Close Dashboard and open My Books
    this->close(); // Close Dashboard first
    myBooks myBooks(ui->label_7->text(), ui->label_8->text(), nullptr);
    myBooks.exec();
}


void Dashboard::addBookToTable(const QString &title, const QString &author, const QString &genre, const QString &status)
{
    int currentRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRow);

    ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(title));  // Title
    ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(author)); // Author
    ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(genre));  // Genre
    ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(status)); // Status
}
