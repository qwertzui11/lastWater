#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include "ship.hpp"

class collector : public ship
{
public:
    collector(sf::Image *img, sf::RenderWindow *rw, sf::Color col) : ship(img, rw, col) {;}
};

#endif // COLLECTOR_HPP
