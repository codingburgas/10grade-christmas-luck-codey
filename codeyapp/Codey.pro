QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
CONFIG += sdk_no_version_check
# Disable deprecated APIs for Qt 6
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Include directories
INCLUDEPATH += $$PWD/presentationLayer \
               $$PWD/dataAccessLayer

# Source files
SOURCES += \
    main.cpp \
    dataAccessLayer/dbConnection.cpp \
    presentationLayer/mybooks.cpp \
    presentationLayer/dashboard.cpp \
    presentationLayer/authwindow.cpp \
    presentationLayer/mainwindow.cpp \
    presentationLayer/writebook.cpp \
    presentationLayer/readbook.cpp \
    presentationLayer/rent.cpp

# Header files
HEADERS += \
    dataAccessLayer/dbConnection.h \
    presentationLayer/mybooks.h \
    presentationLayer/dashboard.h \
    presentationLayer/authwindow.h \
    presentationLayer/mainwindow.h \
    presentationLayer/writebook.h \
    presentationLayer/readbook.h \
    presentationLayer/rent.h

# UI files
FORMS += \
    presentationLayer/mybooks.ui \
    presentationLayer/dashboard.ui \
    presentationLayer/authwindow.ui \
    presentationLayer/mainwindow.ui \
    presentationLayer/writebook.ui \
    presentationLayer/readbook.ui \
    presentationLayer/rent.ui

# Resource files
RESOURCES += \
    resources.qrc

# Library paths
LIBS += -L/Users/ani/Documents/School/sqlapi/lib \
        -L/opt/homebrew/opt/mysql/lib

# Include paths for libraries
INCLUDEPATH += /Users/ani/Documents/School/sqlapi/include

# Link against required libraries
LIBS += -lSqlAPI -lmysqlclient

# Automatic handling of moc, uic, and rcc
QMAKE_FEATURES += uic_moc_rc
