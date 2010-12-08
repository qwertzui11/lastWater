#include "planet.hpp"

planet::planet(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
{

}

void planet::render()
{
    m_rw->Draw(m_sprite);
}

void planet::update()
{
   // m_sprite.Move((m_goTo - m_sprite.GetPosition()) * timeLastFrame);
}
