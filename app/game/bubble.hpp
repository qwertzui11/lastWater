#ifndef BUBBLE_HPP
#define BUBBLE_HPP

#include "collectable.hpp"

class bubble : public collectable
{
public:
    bubble(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw);
    ~bubble();

    static std::vector <bubble*> g_bubbles;
};

#endif // BUBBLE_HPP
