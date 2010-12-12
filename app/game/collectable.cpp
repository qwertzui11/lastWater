#include "collectable.hpp"

collectable::collectable(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
    , m_collector(0)
{
    m_sprite.SetCenter(m_sprite.GetSize().x/2.f, m_sprite.GetSize().y/2.f);
}

collectable::~collectable()
{

}

void collectable::render ()
{
    m_rw->Draw(m_sprite);
}

void collectable::setCollector(collector *set)
{
    m_collector = set;
}

collector * collectable::getCollector()
{
    return m_collector;
}

