#-------------------------------------------------
#
# Project created by QtCreator 2010-12-08T12:38:02
#
#-------------------------------------------------

QT       -= core gui

TARGET = game
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

# INCLUDEPATH += /home/markus/Documents/dev/projects/lastWater/dependencies/linux/include/

unix
{
LIBS+= -lsfml-graphics -lsfml-window -lsfml-system
}

win32
{
    LIBS+=
    INCLUDEPATH+=
}
