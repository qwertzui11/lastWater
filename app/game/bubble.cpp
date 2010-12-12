#include "bubble.hpp"
#include "useful.hpp"

std::vector <bubble*> bubble::g_bubbles;

bubble::bubble(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw)
        : collectable(img, rw)
{
    m_sprite.SetPosition(pos);

    g_bubbles.push_back(this);
}

bubble::~bubble()
{
    findAndDelete<bubble>(&g_bubbles, this);
}
