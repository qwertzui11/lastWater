#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include "ship.hpp"

class collector : public ship
{
public:
    collector(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col) : ship(pos, img, rw, col) {;}
};

#endif // COLLECTOR_HPP
