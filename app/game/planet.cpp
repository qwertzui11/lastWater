#include "planet.hpp"

planet::planet(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
    , m_pos(0.f, 0.f)
    , m_waterLvl(0)
{

}

void planet::render()
{
    m_rw->Draw(m_sprite);
}

void planet::update(int lvl)
{
   m_waterLvl = lvl;
}

void planet::positon(sf::Vector2f pos)
{
    m_pos = pos;
    m_sprite.SetPosition(m_pos);
}
