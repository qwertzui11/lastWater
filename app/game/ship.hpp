#ifndef SHIP_HPP
#define SHIP_HPP

#include "SFML/Graphics.hpp"

class ship
{
public:
    ship(sf::Image *img, sf::RenderWindow *rw, sf::Color col);
    ~ship();

    void update(float timeLastFrame);
    void render();
    sf::Vector2f pos();

    void goTo(sf::Vector2f goTo);

    static std::vector<ship*> g_ships;
    static const float g_radius = 30.f;
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_goTo;
};

#endif // SHIP_HPP
