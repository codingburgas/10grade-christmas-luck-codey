/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_authWindow
{
public:
    QLabel *sideLampBackground;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *authWindow)
    {
        if (authWindow->objectName().isEmpty())
            authWindow->setObjectName("authWindow");
        authWindow->resize(1300, 800);
        authWindow->setStyleSheet(QString::fromUtf8("background-color: #DEE33E;"));
        sideLampBackground = new QLabel(authWindow);
        sideLampBackground->setObjectName("sideLampBackground");
        sideLampBackground->setGeometry(QRect(0, 0, 1301, 801));
        sideLampBackground->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        sideLampBackground->setTextFormat(Qt::TextFormat::AutoText);
        sideLampBackground->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/sideLampBackground.png")));
        sideLampBackground->setWordWrap(true);
        label = new QLabel(authWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 70, 221, 181));
        label->setStyleSheet(QString::fromUtf8("font: 900 40pt \"Segoe UI\";\n"
"color: black;\n"
"background-color: transparent;"));
        label_2 = new QLabel(authWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 580, 391, 91));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: #6D6D6D;\n"
"background-color: transparent;"));
        label_2->setWordWrap(true);
        lineEdit = new QLineEdit(authWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(980, 220, 251, 50));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-color: rgb(0, 0, 0);\n"
"border: 20px;\n"
"border-radius: 8px;"));
        label_3 = new QLabel(authWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(980, 190, 101, 20));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: black;\n"
"font: 12pt \"Segoe UI\";"));
        lineEdit_2 = new QLineEdit(authWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(980, 330, 251, 50));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-color: rgb(0, 0, 0);\n"
"border: 20px;\n"
"border-radius: 8px;"));
        label_4 = new QLabel(authWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(980, 300, 101, 20));
        label_4->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: black;\n"
"font: 12pt \"Segoe UI\";"));
        comboBox = new QComboBox(authWindow);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(980, 440, 251, 50));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"  border: none;\n"
"  border-radius: 8px;\n"
"  font: 12pt \"Segoe UI\";"));
        label_5 = new QLabel(authWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(980, 410, 121, 20));
        label_5->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: black;\n"
"font: 12pt \"Segoe UI\";"));
        pushButton = new QPushButton(authWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(980, 522, 121, 51));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"border-color: rgb(0, 0, 0);\n"
"       color: rgb(0, 0, 0);\n"
"       background-color: rgb(250, 255, 74);\n"
"       border: 1px;\n"
"       border-color: rgb(0, 0, 0);\n"
"       border-radius: 14px;\n"
"   "));
        pushButton->setCheckable(false);

        retranslateUi(authWindow);

        QMetaObject::connectSlotsByName(authWindow);
    } // setupUi

    void retranslateUi(QDialog *authWindow)
    {
        authWindow->setWindowTitle(QCoreApplication::translate("authWindow", "Codey", nullptr));
        sideLampBackground->setText(QString());
        label->setText(QCoreApplication::translate("authWindow", "Be\n"
"Better", nullptr));
        label_2->setText(QCoreApplication::translate("authWindow", "Create a Codey account to discover amazing authors or become one yourself. Share your stories and let the world see your creativity!", nullptr));
        label_3->setText(QCoreApplication::translate("authWindow", "Username", nullptr));
        label_4->setText(QCoreApplication::translate("authWindow", "Password", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("authWindow", "Reader", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("authWindow", "Writer", nullptr));

        label_5->setText(QCoreApplication::translate("authWindow", "Choose a role", nullptr));
        pushButton->setText(QCoreApplication::translate("authWindow", "Join", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authWindow: public Ui_authWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
