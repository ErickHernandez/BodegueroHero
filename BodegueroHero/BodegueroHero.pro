#-------------------------------------------------
#
# Project created by QtCreator 2013-01-26T23:08:17
#
#-------------------------------------------------

QT       += core gui
QT       += xml

TARGET = BodegueroHero
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlpuzzletree.cpp \
    graphicsscenepreview.cpp \
    graphicsscenegame.cpp \
    dragwidget.cpp \
    action.cpp \
    caja.cpp \
    windialog.cpp

HEADERS  += mainwindow.h \
    dbConnection.h \
    xmlpuzzletree.h \
    MyXmlHandler.h \
    graphicsscenepreview.h \
    graphicsscenegame.h \
    dragwidget.h \
    action.h \
    caja.h \
    windialog.h

FORMS    += mainwindow.ui \
    windialog.ui

RESOURCES += \
    Images.qrc

OTHER_FILES += \
    ../../../../Desktop/Ingenieria de Software/screen manager.txt
QT       += sql
