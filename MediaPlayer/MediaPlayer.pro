#-------------------------------------------------
#
# Project created by QtCreator 2023-02-09T14:19:50
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = MediaPlayer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
            Common/commondef.h

FORMS    += mainwindow.ui

MOC_DIR             = $$PWD/../Temp/moc
RCC_DIR             = $$PWD/../Temp/rcc
UI_DIR              = $$PWD/../Temp/ui
OBJECTS_DIR         = $$PWD/../Temp/obj
DESTDIR = $$PWD/../Bin

include($$PWD\Media\media.pri)

INCLUDEPATH += $$PWD/Common $$PWD/Media
DEPENDPATH += $$PWD/Common $$PWD/Media

unix|win32: LIBS += -L$$PWD/WinLib/ffmpeg/lib/ -lavcodec -lavdevice -lavfilter -lavformat -lavutil  -lswresample -lswscale

INCLUDEPATH += $$PWD/WinLib/ffmpeg/include
DEPENDPATH += $$PWD/WinLib/ffmpeg/include
