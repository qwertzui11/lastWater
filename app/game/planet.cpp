#include "planet.hpp"

planet::planet(sf::Image *img, sf::RenderWindow *rw, sf::Vector2f pos, sf::Vector2f cpos, sf::Color col)
    : m_rw(rw)
    , m_sprite(*img)
    , m_pos(pos)
    , m_cpos(cpos)
    , m_waterLvl(0)
    , m_ironLvl(0)
{
    m_sprite.SetColor(col);
    m_sprite.SetCenter(m_cpos);
    m_sprite.SetPosition(m_pos);
}

void planet::render()
{

    m_rw->Draw(m_sprite);
}

void planet::update(float time)
{
    m_sprite.SetRotation(m_sprite.GetRotation()+0.02f);
}

void planet::addWater(int lvl)
{
    m_waterLvl = lvl;
}

void planet::addIron(int lvl)
{
    m_ironLvl = lvl;
}
