#ifndef SHIP_HPP
#define SHIP_HPP

#include "SFML/Graphics.hpp"

class ship
{
public:
    ship(sf::Image *img, sf::RenderWindow *rw, sf::Color col);

    void update(float timeLastFrame);
    void render();

    void goTo(sf::Vector2f goTo);
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_goTo;
};

#endif // SHIP_HPP
