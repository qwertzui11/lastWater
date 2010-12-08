#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "world.hpp"
#include "planet.hpp"

class game
{
public:
    game();
    ~game();

    /* startup */
    void initialise();

    int run();

    void update(float timeLastFrame);
    void render();
private:

    sf::RenderWindow m_window;
    sf::Image m_imgShip;
    sf::Image m_img1p;
    sf::Image m_imgWater;
    ship *m_test;
    world m_world;
    planet *m_1p;
    planet *m_water;

};

#endif // GAME_HPP
