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
    ExcelView/wbook.cpp \
    ExcelView/ssheet.cpp \
    ExcelView/excelview.cpp

HEADERS  += mainwindow.h \
    ExcelView/wbook.h \
    ExcelView/ssheet.h \
    ExcelView/excelview.h

OTHER_FILES +=

FORMS += \
    ExcelView/wbook.ui \
    ExcelView/ssheet.ui
