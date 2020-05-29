#-------------------------------------------------
#
# Project created by QtCreator 2020-05-27T10:41:24
#
#-------------------------------------------------

QT       += core gui charts printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    myplot.cpp \
    mytablecard.cpp \
    mytabwidget.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    myplot.h \
    mytablecard.h \
    mytabwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc \
    resourse.qrc
