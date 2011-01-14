#include "stateManager.hpp"
#include "guiMainMenu.hpp"

#include "SFML/Graphics/RenderWindow.hpp"


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    sf::RenderWindow rw(sf::VideoMode(1920, 1020, 32), "lastWater");

    stateManager mgr(new guiMainMenu(&rw), &rw);
    return mgr.run();

    /*game gm(&rw);
    gm.initialise();

    return gm.run();*/

}
