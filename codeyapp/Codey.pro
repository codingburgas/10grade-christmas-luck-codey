QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


INCLUDEPATH += $$PWD/presentationLayer
DISTFILES += \
    dataAccessLayer/users.txt \
    dataAccessLayer/books.txt

SOURCES += \
    main.cpp \
    dataAccessLayer/database.cpp \
    presentationLayer/deposit.cpp \
    presentationLayer/mybooks.cpp \
    presentationLayer/dashboard.cpp \
    presentationLayer/authwindow.cpp \
    presentationLayer/mainwindow.cpp \
    presentationLayer/writebook.cpp \
    presentationLayer/readbook.cpp \
    presentationLayer/rent.cpp \
    presentationLayer/withdraw.cpp

HEADERS += \
    dataAccessLayer/database.h \
    presentationLayer/deposit.h \
    presentationLayer/mybooks.h \
    presentationLayer/dashboard.h \
    presentationLayer/authwindow.h \
    presentationLayer/mainwindow.h \
    presentationLayer/writebook.h \
    presentationLayer/readbook.h \
    presentationLayer/rent.h \
    presentationLayer/withdraw.h

FORMS += \
    presentationLayer/deposit.ui \
    presentationLayer/mybooks.ui \
    presentationLayer/dashboard.ui \
    presentationLayer/authwindow.ui \
    presentationLayer/mainwindow.ui \
    presentationLayer/writebook.ui \
    presentationLayer/readbook.ui \
    presentationLayer/rent.ui \
    presentationLayer/withdraw.ui

RESOURCES += resource.qrc \
    resources.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
