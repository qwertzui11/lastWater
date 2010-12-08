#ifndef PLANET_HPP
#define PLANET_HPP

#include "SFML/Graphics.hpp"

class planet
{
public:
    planet(sf::Image *img, sf::RenderWindow *rw);

    void update();
    void render();

private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

};

#endif // PLANET_HPP
