#include "ship.hpp"

ship::ship(sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : m_rw(rw)
    , m_sprite(*img)
    , m_goTo(0.f, 0.f)
{
    m_sprite.SetColor(col);
}

void ship::render()
{
    m_rw->Draw(m_sprite);
}

void ship::update(float timeLastFrame)
{
    m_sprite.Move((m_goTo - m_sprite.GetPosition()) * timeLastFrame);
}

void ship::goTo(sf::Vector2f goTo)
{
    m_goTo = goTo;
}
