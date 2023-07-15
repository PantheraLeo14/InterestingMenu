#-------------------------------------------------
#
# Project created by QtCreator 2023-07-13T09:19:30
#
#-------------------------------------------------

QT       += core gui\
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IM2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    workfun.cpp

HEADERS  += mainwindow.h \
    workfun.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
