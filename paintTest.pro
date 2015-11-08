#-------------------------------------------------
#
# Project created by QtCreator 2015-10-25T08:53:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = paintTest
TEMPLATE = app


SOURCES += main.cpp\
        paintwidget.cpp \
    button.cpp \
    mypoint.cpp

HEADERS  += paintwidget.h \
    button.h \
    mypoint.h

FORMS    += paintwidget.ui
