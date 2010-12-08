#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "world.hpp"
<<<<<<< HEAD
#include "planet.hpp"
=======
#include "asteroid.hpp"
>>>>>>> 9138d7be38f7231c0b0cec76b17ddae23cd12a09

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

    sf::Image m_imgAsteroid;
    ship *m_test;
    world m_world;
    asteroid *m_asteroids;
};

#endif // GAME_HPP
