#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"
#include "world.hpp"
#include "planet.hpp"
#include "asteroid.hpp"
#include "bubble.hpp"
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
    void zoom(float time);

    static const float g_scrollSpeed = 500.f;
    static const float g_zoomSpeed = 20.f;

    sf::RenderWindow m_window;

    sf::Image m_imgCollector;
    sf::Image m_imgAttacker;
    sf::Image m_imgBullet;
    sf::Image m_imgBubble;
    sf::Image m_img1p;
    sf::Image m_imgWater;

    sf::Font m_font;

    world m_world;

    planet *m_planetWater;

    sf::Image m_imgAsteroid;
    // std::vector<asteroid *>m_asteroids;

    float m_nextAsteroid;

    human *m_player;
    std::vector <computer*> m_computers;

    sf::Vector2f m_viewPos;
    float m_zoom;
};

#endif // GAME_HPP
