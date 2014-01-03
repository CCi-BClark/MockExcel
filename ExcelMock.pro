#-------------------------------------------------
#
# Project created by QtCreator 2014-01-03T13:25:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExcelMock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wbook.cpp \
    ssheet.cpp \
    excelmockwidget.cpp

HEADERS  += mainwindow.h \
    wbook.h \
    ssheet.h \
    excelmockwidget.h

FORMS    += \
    wbook.ui \
    ssheet.ui
