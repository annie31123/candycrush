#-------------------------------------------------
#
# Project created by QtCreator 2015-06-05T11:05:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = candycrush
TEMPLATE = app


SOURCES += main.cpp\
        candycrush.cpp \
    basic.cpp \
    chocolate.cpp \
    fourH.cpp \
    candys.cpp \
    Destroy.cpp \
    fourv.cpp \
    nine.cpp \
    three.cpp \
    start.cpp \
    over.cpp

HEADERS  += candycrush.h \
    basic.h \
    chocolate.h \
    fourH.h \
    candys.h \
    Destroy.h \
    fourv.h \
    nine.h \
    three.h \
    start.h \
    over.h

FORMS    += candycrush.ui \
    start.ui \
    over.ui

RESOURCES += \
    image.qrc
