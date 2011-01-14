#include "stateManager.hpp"
#include "guiSinglePlayerSettings.hpp"

#include "SFML/Graphics/RenderWindow.hpp"


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    sf::RenderWindow rw(sf::VideoMode(1024, 700, 32), "lastWater");

    stateManager mgr(new guiSinglePlayerSettings(&rw), &rw);
    return mgr.run();

    /*game gm(&rw);
    gm.initialise();

    return gm.run();*/

}
