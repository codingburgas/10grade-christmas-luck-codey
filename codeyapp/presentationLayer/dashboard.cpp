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


    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});


    connect(ui->searchButton, &QPushButton::clicked, this, &Dashboard::on_searchButton_clicked);

    loadBooks();
}

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

    ui->label_7->setText(username);
    ui->label_8->setText(role);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Title", "Author", "Genre", "Status"});

    loadBooks();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::loadBooks()
{
    QFile file("dataAccessLayer/books.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open books.txt for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList details = line.split(",");

        if (details.size() == 4) {
            int currentRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(currentRow);

            ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(details[0]));
            ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(details[1]));
            ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(details[2]));
            ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(details[3]));
        }
    }

    file.close();
}

void Dashboard::on_pushButton_2_clicked()
{
    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this);
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable);
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_clicked()
{

    writeBook writeBook(ui->label_7->text(), ui->label_8->text(), this);
    connect(&writeBook, &writeBook::bookAdded, this, &Dashboard::addBookToTable);
    writeBook.setModal(true);
    writeBook.exec();
}

void Dashboard::on_pushButton_3_clicked()
{
    this->hide();

    Dashboard Dashboard;
    Dashboard.setModal(true);
    Dashboard.exec();

    this->close();
}

void Dashboard::on_pushButton_4_clicked()
{
    this->close();
    myBooks myBooks(ui->label_7->text(), ui->label_8->text(), nullptr);
    myBooks.exec();
}


void Dashboard::addBookToTable(const QString &title, const QString &author, const QString &genre, const QString &status)
{
    int currentRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(currentRow);

    ui->tableWidget->setItem(currentRow, 0, new QTableWidgetItem(title));
    ui->tableWidget->setItem(currentRow, 1, new QTableWidgetItem(author));
    ui->tableWidget->setItem(currentRow, 2, new QTableWidgetItem(genre));
    ui->tableWidget->setItem(currentRow, 3, new QTableWidgetItem(status));
}


void Dashboard::on_searchButton_clicked()
{
    QString searchText = ui->searchBar->text();

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *titleItem = ui->tableWidget->item(row, 0);

        if (titleItem && titleItem->text().contains(searchText, Qt::CaseInsensitive)) {
            ui->tableWidget->setRowHidden(row, false);
        } else {
            ui->tableWidget->setRowHidden(row, true);
        }
    }
}
