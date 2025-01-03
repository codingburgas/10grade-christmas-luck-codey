/********************************************************************************
** Form generated from reading UI file 'mybooks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYBOOKS_H
#define UI_MYBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myBooks
{
public:
    QFrame *frame;
    QLabel *label_logo;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLabel *label_books;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_libraryIcon;
    QPushButton *pushButton;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QTableWidget *tableWidget;

    void setupUi(QDialog *myBooks)
    {
        if (myBooks->objectName().isEmpty())
            myBooks->setObjectName(QString::fromUtf8("myBooks"));
        myBooks->resize(1300, 800);
        myBooks->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        frame = new QFrame(myBooks);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, -10, 256, 811));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_logo = new QLabel(frame);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(82, 60, 72, 72));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/logo.png")));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 140, 81, 31));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 16pt \"Segoe UI\";"));
        layoutWidget = new QWidget(frame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 300, 106, 26));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";"));

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);

        label_books = new QLabel(layoutWidget);
        label_books->setObjectName(QString::fromUtf8("label_books"));
        label_books->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/booksIcon.png")));

        gridLayout_3->addWidget(label_books, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 250, 131, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: transparent;\n"
"background-color: transparent;"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 251, 58, 24));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";"));
        label_libraryIcon = new QLabel(frame);
        label_libraryIcon->setObjectName(QString::fromUtf8("label_libraryIcon"));
        label_libraryIcon->setGeometry(QRect(52, 251, 17, 21));
        label_libraryIcon->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/libraryIcon.png")));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 300, 121, 29));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: transparent;"));
        label_libraryIcon->raise();
        label_3->raise();
        label_logo->raise();
        label->raise();
        layoutWidget->raise();
        pushButton_3->raise();
        pushButton->raise();
        frame_2 = new QFrame(myBooks);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(250, 0, 1051, 96));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 0, 151, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 18pt \"Segoe UI\";"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 40, 191, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(116, 118, 129);\n"
"font: 300 11pt \"Segoe UI\";\n"
"background-color: transparent;"));
        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(880, 0, 181, 41));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(950, 40, 61, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(116, 118, 129);\n"
"font: 300 11pt \"Segoe UI\";"));
        searchBar = new QLineEdit(frame_2);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setGeometry(QRect(280, 20, 431, 51));
        searchBar->setStyleSheet(QString::fromUtf8("\n"
"     background-color: #F5F5F5;\n"
"     border-radius: 12px;"));
        searchButton = new QPushButton(frame_2);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setGeometry(QRect(730, 20, 91, 51));
        searchButton->setCursor(QCursor(Qt::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;\n"
"border-radius: 12px;\n"
"color: black;"));
        tableWidget = new QTableWidget(myBooks);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font;
        font.setBold(false);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem11);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(335, 190, 921, 581));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(220);

        retranslateUi(myBooks);

        QMetaObject::connectSlotsByName(myBooks);
    } // setupUi

    void retranslateUi(QDialog *myBooks)
    {
        myBooks->setWindowTitle(QCoreApplication::translate("myBooks", "myBooks", nullptr));
        label_logo->setText(QString());
        label->setText(QCoreApplication::translate("myBooks", "Codey", nullptr));
        label_4->setText(QCoreApplication::translate("myBooks", "My books", nullptr));
        label_books->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("myBooks", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("myBooks", "Library", nullptr));
        label_libraryIcon->setText(QString());
        pushButton->setText(QCoreApplication::translate("myBooks", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("myBooks", "My Books", nullptr));
        label_6->setText(QCoreApplication::translate("myBooks", "Let\342\200\231s read something!", nullptr));
        label_7->setText(QCoreApplication::translate("myBooks", "Iva Raykova", nullptr));
        label_8->setText(QCoreApplication::translate("myBooks", "Writer", nullptr));
        searchButton->setText(QCoreApplication::translate("myBooks", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("myBooks", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("myBooks", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("myBooks", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("myBooks", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("myBooks", "Book", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("myBooks", "Book", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("myBooks", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("myBooks", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("myBooks", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("myBooks", "Ttest", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("myBooks", "Ttest", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("myBooks", "Ttest", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(accessibility)
        tableWidget->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
    } // retranslateUi

};

namespace Ui {
    class myBooks: public Ui_myBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYBOOKS_H
