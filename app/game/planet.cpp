#include "planet.hpp"

planet::planet(sf::Image *img, sf::RenderWindow *rw, sf::Vector2f pos)
    : m_rw(rw)
    , m_sprite(*img)
    , m_pos(pos)
    , m_waterLvl(0)
{
    m_sprite.SetPosition(m_pos);
}

void planet::render()
{
    m_rw->Draw(m_sprite);
}

void planet::update(int lvl)
{
   m_waterLvl = lvl;
}
