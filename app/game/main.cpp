#include "stateManager.hpp"
#include "guiSinglePlayerSettings.hpp"

#include "SFML/Graphics/RenderWindow.hpp"
#include "sounds.hpp"


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    sf::RenderWindow rw(sf::VideoMode(1024, 700, 32), "lastWater");//, sf::Style::Fullscreen);

    sounds::g_button = new sf::SoundBuffer();
    sounds::g_button->LoadFromFile("../data/sounds/click.wav");
    sounds::g_shot = new sf::SoundBuffer();
    sounds::g_shot->LoadFromFile("../data/sounds/shot.wav");
    sounds::g_explosion = new sf::SoundBuffer();
    sounds::g_explosion->LoadFromFile("../data/sounds/exlposion.wav");
    sounds::g_win = new sf::SoundBuffer();
    sounds::g_win->LoadFromFile("../data/sounds/win.wav");
    sounds::g_loose = new sf::SoundBuffer();
    sounds::g_loose->LoadFromFile("../data/sounds/loose.wav");

    stateManager mgr(new guiSinglePlayerSettings(&rw), &rw);

    mgr.run();

    /* delete sounds::g_button;
    delete sounds::g_shot;
    delete sounds::g_explosion;
    delete sounds::g_win;
    delete sounds::g_loose;*/

    /*game gm(&rw);
    gm.initialise();

    return gm.run();*/

}
