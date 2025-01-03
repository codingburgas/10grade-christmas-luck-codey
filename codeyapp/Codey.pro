QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/presentationLayer
# Include the SQLAPI++ header file
INCLUDEPATH += $$PWD/sqlapi

# Link the static library
LIBS += -L$$PWD/sqlapi -lsqlapi

SOURCES += \
    main.cpp \
    dataAccessLayer/dbConnection.cpp \
    dataAccessLayer/login.cpp \
    presentationLayer/mybooks.cpp \
    presentationLayer/dashboard.cpp \
    presentationLayer/authwindow.cpp \
    presentationLayer/mainwindow.cpp \
    presentationLayer/writebook.cpp \
    presentationLayer/readbook.cpp \
    presentationLayer/rent.cpp

HEADERS += \
    dataAccessLayer/dbConnection.h \
    presentationLayer/mybooks.h \
    presentationLayer/dashboard.h \
    presentationLayer/authwindow.h \
    presentationLayer/mainwindow.h \
    presentationLayer/writebook.h \
    presentationLayer/readbook.h \
    presentationLayer/rent.h

FORMS += \
    presentationLayer/mybooks.ui \
    presentationLayer/dashboard.ui \
    presentationLayer/authwindow.ui \
    presentationLayer/mainwindow.ui \
    presentationLayer/writebook.ui \
    presentationLayer/readbook.ui \
    presentationLayer/rent.ui

RESOURCES += resource.qrc \   # Added resource.qrc here
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
