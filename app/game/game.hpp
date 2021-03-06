#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio/Sound.hpp>

#include "ship.hpp"
#include "world.hpp"
#include "planet.hpp"
#include "asteroid.hpp"
#include "bubble.hpp"
#include "human.hpp"
#include "computer.hpp"
#include "guiAfterSinglePlayer.hpp"

class game : public state, private stateListener
{
public:
    game(int numComputer, sf::RenderWindow *rw);
    ~game();

    bool event(sf::Event *event);

    void update(float timeLastFrame);
    void render();

    void clear();
private:
    void updateScroll(float time);
    void zoom(float time);
    void resetCamera();

    void done (state *from, state *next);

    static const float g_scrollSpeed = 500.f;
    static const float g_zoomSpeed = 20.f;

    sf::Vector2f createPlanetPosition (unsigned int ind);

    sf::RenderWindow *m_rw;

    sf::Image m_imgCollector;
    sf::Image m_imgAttacker;
    sf::Image m_imgBullet;
    sf::Image m_imgBubble;
    sf::Image m_img1p;
    sf::Image m_imgWater;
    sf::Image m_explosion;

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

    int m_numPlayer;
    float m_worldSize;

    guiAfterSinglePlayer *m_afterSingle;

    sf::Sound m_won;
    sf::Sound m_lost;

    float m_totalWater;
};

#endif // GAME_HPP
