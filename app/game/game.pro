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
    asteroid.cpp \
    player.cpp \
    human.cpp \
    computer.cpp \
    useful.cpp \
    bullet.cpp \
    bubble.cpp \
    collectable.cpp \
    gui/widget.cpp \
    gui/button.cpp \
    gui/statictext.cpp \
    gui/buttonListener.cpp \
    guiMainMenu.cpp \
    guiCredits.cpp \
    guiSinglePlayerSettings.cpp \
    stateListener.cpp \
    stateManager.cpp \
    guiAfterSinglePlayer.cpp \
    explosion.cpp \

HEADERS += \
    game.hpp \
    world.hpp \
    planet.hpp \
    ship.hpp \
    collector.hpp \
    attacker.hpp \
    asteroid.hpp \
    messages.hpp \
    useful.hpp \
    player.hpp \
    human.hpp \
    computer.hpp \
    bullet.hpp \
    bubble.hpp \
    collectable.hpp \
    gui/widget.hpp \
    gui/button.hpp \
    gui/statictext.hpp \
    gui/buttonListener.hpp \
    guiMainMenu.hpp \
    guiCredits.hpp \
    guiSinglePlayerSettings.hpp \
    state.hpp \
    stateListener.hpp \
    stateManager.hpp \
    guiAfterSinglePlayer.hpp \
    explosion.hpp \
 

unix {
    INCLUDEPATH += /home/markus/Documents/dev/projects/lastWater/dependencies/linux/include/
    LIBS+= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
}

win32 {
    LIBS+= C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-graphics.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-window.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-system.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-audio.a C:\Users\andreas\UNI\GameDesign\SFML\lib\libsfml-network.a
    INCLUDEPATH+= C:\Users\andreas\UNI\GameDesign\SFML\include
}

OBJECTS_DIR = ./build
