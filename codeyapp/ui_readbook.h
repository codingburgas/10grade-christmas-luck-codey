/********************************************************************************
** Form generated from reading UI file 'readbook.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READBOOK_H
#define UI_READBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readBook
{
public:
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *readBook)
    {
        if (readBook->objectName().isEmpty())
            readBook->setObjectName(QString::fromUtf8("readBook"));
        readBook->resize(1300, 800);
        label_7 = new QLabel(readBook);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1150, 10, 181, 41));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));
        label_8 = new QLabel(readBook);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1220, 50, 61, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(116, 118, 129);\n"
"font: 300 11pt \"Segoe UI\";"));
        pushButton = new QPushButton(readBook);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 131, 61));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 11pt \"Segoe UI\";\n"
"border-radius: 4px;\n"
"background-color: #FFF;\n"
""));
        scrollArea = new QScrollArea(readBook);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(70, 120, 1171, 641));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: #FFF;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1169, 639));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1171, 631));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label->setWordWrap(true);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(readBook);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(540, 20, 172, 37));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 17pt \"Segoe UI\";"));
        label_3 = new QLabel(readBook);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(590, 50, 71, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"Segoe UI\";"));

        retranslateUi(readBook);

        QMetaObject::connectSlotsByName(readBook);
    } // setupUi

    void retranslateUi(QDialog *readBook)
    {
        readBook->setWindowTitle(QCoreApplication::translate("readBook", "Read a book", nullptr));
        label_7->setText(QCoreApplication::translate("readBook", "Iva Raykova", nullptr));
        label_8->setText(QCoreApplication::translate("readBook", "Writer", nullptr));
        pushButton->setText(QCoreApplication::translate("readBook", "My Books", nullptr));
        label->setText(QCoreApplication::translate("readBook", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla ac tincidunt ante, sed blandit erat. Curabitur nec blandit erat, vitae tempor mauris. Sed tristique molestie leo, ac facilisis libero scelerisque nec. Proin imperdiet odio eget nibh faucibus, at cursus lacus rutrum. Pellentesque ornare pharetra lacus, eu pulvinar orci. Fusce a libero massa. Ut felis mauris, sollicitudin a cursus eget, porta vel eros. Sed at efficitur turpis.\n"
"\n"
"Nunc efficitur luctus metus ac luctus. Sed viverra vel urna nec facilisis. Integer tempor eget dolor id fermentum. Aenean sed libero eget ex volutpat maximus. Fusce odio dolor, ultrices in ultricies eget, tincidunt eget mauris. Praesent vehicula diam in lacus porta molestie. Etiam eget finibus eros, quis lobortis sapien. In hac habitasse platea dictumst. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Pellentesque euismod, arcu nec mattis ultricies, magna risus aliquet nisl, nec sodales odio orci vitae neque. Duis bibendum "
                        "nisl sit amet aliquet posuere. Pellentesque eu ipsum sit amet augue faucibus aliquam et at nibh. Aenean non justo ac massa cursus finibus lacinia vel est. Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n"
"\n"
"Aliquam dolor nibh, feugiat eu ipsum ac, maximus consequat mauris. Integer sit amet pretium odio, eu elementum eros. Donec et orci consectetur, mollis dolor sit amet, imperdiet ante. Maecenas pellentesque facilisis dolor nec cursus. Cras ac hendrerit metus. Sed sollicitudin, purus nec tincidunt eleifend, tellus orci elementum orci, et euismod arcu augue non nibh. Aliquam imperdiet pretium elit, ut hendrerit leo interdum eget. Ut eget felis dignissim metus faucibus accumsan vitae id arcu. Phasellus auctor pulvinar arcu vel sollicitudin. Vivamus rutrum mattis ex, a pharetra purus.\n"
"\n"
"Praesent aliquet, lorem vitae tincidunt mattis, arcu nunc dictum sapien, sit amet interdum leo mi ut dui. Sed ultricies vehicula nisl, eu aliquet eros semper id. Aliquam et neque at diam suscipit maximus at qu"
                        "is mi. Proin sit amet scelerisque eros. Nullam tincidunt lorem et velit ullamcorper, sed vulputate neque consectetur. Ut imperdiet efficitur justo. Ut vel tempus erat. Proin metus lacus, varius eget suscipit ac, interdum non tortor.\n"
"\n"
"Donec sit amet venenatis urna. Quisque vehicula tempus nibh sit amet euismod. Donec vehicula arcu et turpis vehicula fringilla. Praesent fringilla metus id orci tincidunt finibus. Curabitur lacinia id libero id volutpat. Sed sit amet porttitor ligula. Mauris vel pharetra orci.", nullptr));
        label_2->setText(QCoreApplication::translate("readBook", "Lorem Ipsum", nullptr));
        label_3->setText(QCoreApplication::translate("readBook", "Test Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readBook: public Ui_readBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READBOOK_H
