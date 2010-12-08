#include "asteroid.hpp"
#include "useful.hpp"

asteroid::asteroid(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
    , m_dir(normalize(sf::Vector2f(rand(), rand())))
{
    if (rand()%2 == 0)
    {
        m_dir.x*=-1.f;
    }
    if (rand()%2 == 0)
    {
        m_dir.y*=-1.f;
    }
}

void asteroid::update (float timeLastFrame)
{
    m_sprite.Move(m_dir*timeLastFrame*10.0f);
}

void asteroid::render ()
{
    m_rw->Draw(m_sprite);
}
