/********************************************************************************
** Form generated from reading UI file 'rent.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENT_H
#define UI_RENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Rent
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLabel *label_9;

    void setupUi(QDialog *Rent)
    {
        if (Rent->objectName().isEmpty())
            Rent->setObjectName(QString::fromUtf8("Rent"));
        Rent->resize(415, 270);
        Rent->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;"));
        pushButton = new QPushButton(Rent);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(272, 188, 91, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 4px;\n"
"color: black;\n"
"background-color: #DEE33E;\n"
"font: 12pt \"Segoe UI\";"));
        label = new QLabel(Rent);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 131, 41));
        label->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Rent);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 60, 63, 20));
        label_3 = new QLabel(Rent);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 80, 81, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: transparent;"));
        label_4 = new QLabel(Rent);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 110, 63, 20));
        label_5 = new QLabel(Rent);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 130, 81, 20));
        label_5->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: transparent;"));
        label_6 = new QLabel(Rent);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 180, 81, 20));
        label_6->setStyleSheet(QString::fromUtf8("font: 700 10pt \"Segoe UI\";\n"
"background-color: transparent;"));
        label_7 = new QLabel(Rent);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 160, 63, 20));
        label_8 = new QLabel(Rent);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(270, 60, 63, 20));
        lineEdit = new QLineEdit(Rent);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(270, 90, 51, 28));
        label_9 = new QLabel(Rent);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(330, 90, 63, 20));

        retranslateUi(Rent);

        QMetaObject::connectSlotsByName(Rent);
    } // setupUi

    void retranslateUi(QDialog *Rent)
    {
        Rent->setWindowTitle(QCoreApplication::translate("Rent", "Rent a book", nullptr));
        pushButton->setText(QCoreApplication::translate("Rent", "Rent", nullptr));
        label->setText(QCoreApplication::translate("Rent", "Rent a book", nullptr));
        label_2->setText(QCoreApplication::translate("Rent", "Title", nullptr));
        label_3->setText(QCoreApplication::translate("Rent", "Testt", nullptr));
        label_4->setText(QCoreApplication::translate("Rent", "Author", nullptr));
        label_5->setText(QCoreApplication::translate("Rent", "Test Test", nullptr));
        label_6->setText(QCoreApplication::translate("Rent", "Ttest", nullptr));
        label_7->setText(QCoreApplication::translate("Rent", "Genre", nullptr));
        label_8->setText(QCoreApplication::translate("Rent", "Rent for", nullptr));
        label_9->setText(QCoreApplication::translate("Rent", "days", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rent: public Ui_Rent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENT_H
