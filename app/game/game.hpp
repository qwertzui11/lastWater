#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "world.hpp"
#include "asteroid.hpp"

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
    sf::Image m_imgAsteroid;
    ship *m_test;
    world m_world;
    asteroid *m_asteroids;
};

#endif // GAME_HPP
