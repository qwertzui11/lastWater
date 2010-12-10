#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "world.hpp"
#include "planet.hpp"
#include "asteroid.hpp"
#include "human.hpp"
#include "computer.hpp"
#include <vector>

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
    void updateScroll(float time);

    static const float g_scrollSpeed = 500.f;

    sf::RenderWindow m_window;
    sf::Image m_imgShip;

    sf::Image m_img1p;
    sf::Image m_img2p;
    sf::Image m_imgWater;
    world m_world;
    planet *m_1p;
    planet *m_2p;
    planet *m_water;

    sf::Image m_imgAsteroid;
    std::vector<asteroid *>m_asteroids;

    float m_nextAsteroid;

    human m_player;
    std::vector <computer*> m_computers;

    sf::Vector2f m_viewPos;
};

#endif // GAME_HPP
