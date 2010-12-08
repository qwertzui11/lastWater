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


SOURCES += main.cpp \
    game.cpp \
    world.cpp \
    planet.cpp \
    ship.cpp \
    collector.cpp \
    attacker.cpp \
    asteroid.cpp

# INCLUDEPATH += /home/markus/Documents/dev/projects/lastWater/dependencies/linux/include/

unix {
    LIBS+= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
}

# dingdong
win32 {
    LIBS+= C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-graphics.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-window.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-system.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-audio.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-network.a
    INCLUDEPATH+= C:\Users\andreas\UNI\GameDesign\SFML\include
}

HEADERS += \
    game.hpp \
    world.hpp \
    planet.hpp \
    ship.hpp \
    collector.hpp \
    attacker.hpp \
    asteroid.hpp \
    messages.hpp \
    useful.hpp
