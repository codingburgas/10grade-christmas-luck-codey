/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_lampBackground;
    QLabel *label_text;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_linesBackground;
    QLabel *label_backgroundText;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 800);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 200));
        MainWindow->setMaximumSize(QSize(1300, 1000));
        MainWindow->setSizeIncrement(QSize(1300, 800));
        MainWindow->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamilies({QString::fromUtf8("Inter")});
        font.setBold(false);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 227, 62);"));
        MainWindow->setTabShape(QTabWidget::TabShape::Triangular);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_lampBackground = new QLabel(centralwidget);
        label_lampBackground->setObjectName("label_lampBackground");
        label_lampBackground->setGeometry(QRect(610, 0, 700, 801));
        label_lampBackground->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label_lampBackground->setPixmap(QPixmap(QString::fromUtf8("../assets/images/topLampBackground.png")));
        label_lampBackground->setScaledContents(false);
        label_lampBackground->setWordWrap(false);
        label_lampBackground->setMargin(0);
        label_text = new QLabel(centralwidget);
        label_text->setObjectName("label_text");
        label_text->setGeometry(QRect(250, 310, 771, 171));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(44);
        font1.setWeight(QFont::Black);
        font1.setItalic(false);
        label_text->setFont(font1);
        label_text->setStyleSheet(QString::fromUtf8("color: black;\n"
"font: 900 44pt \"Segoe UI\";\n"
"background-color: transparent;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1010, 440, 187, 53));
        pushButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"border-color: rgb(0, 0, 0);\n"
"        color: rgb(0, 0, 0);\n"
"        background-color: rgb(250, 255, 74);\n"
"	border: 1px;\n"
"        border-color: rgb(0, 0, 0);\n"
"        border-radius: 14px;\n"
"    "));
        pushButton->setCheckable(false);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setEnabled(false);
        label->setGeometry(QRect(1003, 500, 231, 20));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"color: #6D6D6D;\n"
"font: 350 11pt \"Segoe UI\";"));
        label_linesBackground = new QLabel(centralwidget);
        label_linesBackground->setObjectName("label_linesBackground");
        label_linesBackground->setGeometry(QRect(40, 40, 81, 801));
        label_linesBackground->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        label_linesBackground->setPixmap(QPixmap(QString::fromUtf8("../assets/images/backgroundLines.png")));
        label_linesBackground->setScaledContents(false);
        label_linesBackground->setWordWrap(false);
        label_linesBackground->setMargin(0);
        label_backgroundText = new QLabel(centralwidget);
        label_backgroundText->setObjectName("label_backgroundText");
        label_backgroundText->setGeometry(QRect(250, 10, 831, 781));
        label_backgroundText->setStyleSheet(QString::fromUtf8("background-color: transparent"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Codey", nullptr));
        label_lampBackground->setText(QString());
        label_text->setText(QCoreApplication::translate("MainWindow", "Write your own book\n"
" or visit our library", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Join", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "And learn more about Codey!", nullptr));
        label_linesBackground->setText(QString());
        label_backgroundText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
