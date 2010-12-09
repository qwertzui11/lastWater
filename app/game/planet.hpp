#ifndef PLANET_HPP
#define PLANET_HPP

#include "SFML/Graphics.hpp"

class planet
{
public:
    planet(sf::Image *img, sf::RenderWindow *rw);

    void update();
    void render();

    void positon(sf::Vector2f pos);

private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_pos;
    int m_waterLvl;
};

#endif // PLANET_HPP
