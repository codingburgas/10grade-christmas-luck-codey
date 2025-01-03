/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QFrame *frame;
    QLabel *label_logo;
    QLabel *label;
    QLabel *label_write;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_3;
    QLabel *label_libraryIcon;
    QLabel *label_4;
    QLabel *label_books;
    QFrame *frame_2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *searchBar;
    QPushButton *searchButton;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QString::fromUtf8("Dashboard"));
        Dashboard->resize(1300, 800);
        Dashboard->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 245, 245);"));
        frame = new QFrame(Dashboard);
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
        label_write = new QLabel(frame);
        label_write->setObjectName(QString::fromUtf8("label_write"));
        label_write->setGeometry(QRect(50, 360, 16, 17));
        label_write->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/writeIcon.png")));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 355, 108, 24));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 350, 151, 29));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("color: transparent;\n"
"background-color: transparent;"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 250, 131, 31));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: transparent;\n"
"background-color: transparent;"));
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 300, 151, 29));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: transparent;"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 251, 58, 24));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";"));
        label_libraryIcon = new QLabel(frame);
        label_libraryIcon->setObjectName(QString::fromUtf8("label_libraryIcon"));
        label_libraryIcon->setGeometry(QRect(52, 251, 17, 21));
        label_libraryIcon->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/libraryIcon.png")));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 300, 81, 24));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 600 11pt \"Segoe UI\";"));
        label_books = new QLabel(frame);
        label_books->setObjectName(QString::fromUtf8("label_books"));
        label_books->setGeometry(QRect(51, 301, 16, 17));
        label_books->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/booksIcon.png")));
        label_3->raise();
        label_logo->raise();
        label->raise();
        label_write->raise();
        label_5->raise();
        pushButton->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        frame_2 = new QFrame(Dashboard);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(250, 0, 1051, 96));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 0, 111, 41));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 18pt \"Segoe UI\";"));
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 40, 191, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(116, 118, 129);\n"
"font: 300 11pt \"Segoe UI\";"));
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
        pushButton_2 = new QPushButton(Dashboard);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1140, 128, 111, 41));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 4px;\n"
"font: 10pt \"Segoe UI\";\n"
"background: #DEE33E;\n"
"color: black;"));
        tableWidget = new QTableWidget(Dashboard);
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

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QDialog *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "Dashboard", nullptr));
        label_logo->setText(QString());
        label->setText(QCoreApplication::translate("Dashboard", "Codey", nullptr));
        label_write->setText(QString());
        label_5->setText(QCoreApplication::translate("Dashboard", "Write a book", nullptr));
        pushButton->setText(QCoreApplication::translate("Dashboard", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dashboard", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dashboard", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "Library", nullptr));
        label_libraryIcon->setText(QString());
        label_4->setText(QCoreApplication::translate("Dashboard", "My books", nullptr));
        label_books->setText(QString());
        label_2->setText(QCoreApplication::translate("Dashboard", "Library", nullptr));
        label_6->setText(QCoreApplication::translate("Dashboard", "Let's discover some work", nullptr));
        label_7->setText(QCoreApplication::translate("Dashboard", "Iva Raykova", nullptr));
        label_8->setText(QCoreApplication::translate("Dashboard", "Writer", nullptr));
        searchButton->setText(QCoreApplication::translate("Dashboard", "Search", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dashboard", "Write a book", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Dashboard", "Title", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Dashboard", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Dashboard", "Genre", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Dashboard", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Dashboard", "Book", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Dashboard", "Book", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Dashboard", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(0, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Dashboard", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Dashboard", "Test", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(1, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Dashboard", "Ttest", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(1, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Dashboard", "Ttest", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(1, 2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Dashboard", "Ttest", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(accessibility)
        tableWidget->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
