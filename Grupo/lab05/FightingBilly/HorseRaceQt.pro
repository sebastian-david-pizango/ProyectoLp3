QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HorseRaceQt
TEMPLATE = app

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h \
           horsesec2.h

FORMS += mainwindow.ui