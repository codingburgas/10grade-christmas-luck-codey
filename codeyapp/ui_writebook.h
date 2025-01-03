/********************************************************************************
** Form generated from reading UI file 'writebook.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITEBOOK_H
#define UI_WRITEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_writeBook
{
public:
    QFrame *frame;
    QLabel *writeImage;
    QLabel *label;
    QLabel *titleLable;
    QLabel *genreLabel;
    QLineEdit *titleInput;
    QLineEdit *genreInput;
    QLabel *contentLabel;
    QLineEdit *contentInput;
    QLabel *role;
    QLabel *username;
    QPushButton *cancelButton;
    QPushButton *writeButton;

    void setupUi(QDialog *writeBook)
    {
        if (writeBook->objectName().isEmpty())
            writeBook->setObjectName(QString::fromUtf8("writeBook"));
        writeBook->resize(1300, 800);
        writeBook->setStyleSheet(QString::fromUtf8("background: #F5F5F5;"));
        frame = new QFrame(writeBook);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(126, 89, 1049, 621));
        frame->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 4px;"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        writeImage = new QLabel(frame);
        writeImage->setObjectName(QString::fromUtf8("writeImage"));
        writeImage->setGeometry(QRect(750, 0, 281, 211));
        writeImage->setStyleSheet(QString::fromUtf8("background-color: transparent;"));
        writeImage->setPixmap(QPixmap(QString::fromUtf8(":/assets/images/writeImage.png")));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 40, 261, 44));
        label->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 700 25pt \"Segoe UI\";"));
        titleLable = new QLabel(frame);
        titleLable->setObjectName(QString::fromUtf8("titleLable"));
        titleLable->setGeometry(QRect(90, 130, 63, 20));
        titleLable->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));
        genreLabel = new QLabel(frame);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setGeometry(QRect(590, 130, 63, 20));
        genreLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));
        titleInput = new QLineEdit(frame);
        titleInput->setObjectName(QString::fromUtf8("titleInput"));
        titleInput->setGeometry(QRect(90, 160, 361, 41));
        titleInput->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 0.5px solid rgb(62, 62, 62);\n"
"background: #FAFAFA;"));
        genreInput = new QLineEdit(frame);
        genreInput->setObjectName(QString::fromUtf8("genreInput"));
        genreInput->setGeometry(QRect(590, 160, 221, 41));
        genreInput->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 0.5px solid rgb(62, 62, 62);\n"
"background: #FAFAFA;"));
        contentLabel = new QLabel(frame);
        contentLabel->setObjectName(QString::fromUtf8("contentLabel"));
        contentLabel->setGeometry(QRect(90, 250, 91, 20));
        contentLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"Segoe UI\";"));
        contentInput = new QLineEdit(frame);
        contentInput->setObjectName(QString::fromUtf8("contentInput"));
        contentInput->setGeometry(QRect(90, 290, 891, 301));
        contentInput->setStyleSheet(QString::fromUtf8("border-radius: 8px;\n"
"border: 0.5px solid rgb(62, 62, 62);\n"
"background: #FAFAFA;"));
        role = new QLabel(writeBook);
        role->setObjectName(QString::fromUtf8("role"));
        role->setGeometry(QRect(1220, 50, 61, 20));
        role->setStyleSheet(QString::fromUtf8("color: rgb(116, 118, 129);\n"
"font: 300 11pt \"Segoe UI\";"));
        username = new QLabel(writeBook);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(1150, 10, 181, 41));
        username->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 15pt \"Segoe UI\";"));
        cancelButton = new QPushButton(writeBook);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(130, 730, 83, 45));
        cancelButton->setCursor(QCursor(Qt::PointingHandCursor));
        cancelButton->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 600 12pt \"Segoe UI\";\n"
"border-radius: 4px;\n"
"background: #ED5B5B;"));
        writeButton = new QPushButton(writeBook);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));
        writeButton->setGeometry(QRect(230, 730, 141, 45));
        writeButton->setCursor(QCursor(Qt::PointingHandCursor));
        writeButton->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 600 12pt \"Segoe UI\";\n"
"border-radius: 4px;\n"
"background: #DEE33E;"));

        retranslateUi(writeBook);

        QMetaObject::connectSlotsByName(writeBook);
    } // setupUi

    void retranslateUi(QDialog *writeBook)
    {
        writeBook->setWindowTitle(QCoreApplication::translate("writeBook", "Write a book", nullptr));
        writeImage->setText(QString());
        label->setText(QCoreApplication::translate("writeBook", "Write a book", nullptr));
        titleLable->setText(QCoreApplication::translate("writeBook", "Title", nullptr));
        genreLabel->setText(QCoreApplication::translate("writeBook", "Genre", nullptr));
        contentLabel->setText(QCoreApplication::translate("writeBook", "Content", nullptr));
        role->setText(QCoreApplication::translate("writeBook", "Writer", nullptr));
        username->setText(QCoreApplication::translate("writeBook", "Iva Raykova", nullptr));
        cancelButton->setText(QCoreApplication::translate("writeBook", "Cancel", nullptr));
        writeButton->setText(QCoreApplication::translate("writeBook", "Write a book", nullptr));
    } // retranslateUi

};

namespace Ui {
    class writeBook: public Ui_writeBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEBOOK_H
