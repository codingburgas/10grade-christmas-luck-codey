QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/presentationLayer

SOURCES += \
    main.cpp \
    presentationLayer/authwindow.cpp \
    presentationLayer/mainwindow.cpp

HEADERS += \
    presentationLayer/authwindow.h \
    presentationLayer/mainwindow.h

FORMS += \
    presentationLayer/authwindow.ui \
    presentationLayer/mainwindow.ui

RESOURCES += resource.qrc \   # Added resource.qrc here
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
