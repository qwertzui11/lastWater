#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include "collectable.hpp"

class bubble : public collectable
{
public:
    bubble(sf::Image *img, sf::RenderWindow *rw);
    ~bubble();
};

#endif // BUBBLE_HPP
