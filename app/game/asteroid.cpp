#include "asteroid.hpp"
#include "useful.hpp"

#include <iostream>

asteroid::asteroid(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
{
    // kommt der asteroid von oben?
    int start = rand()%4;
    float dir = (rand()%2000)-1000;
    dir/=1000.f;
    if (start == 0)
    {
        m_sprite.SetPosition(rand()%2000, -(int)img->GetHeight());
        m_dir = normalize(sf::Vector2f(dir, 1));
    }
    // unten
    if (start == 1)
    {
        m_sprite.SetPosition(rand()%2000, 2000);
        m_dir = normalize(sf::Vector2f(dir, -1));
    }
    // links
    if (start == 2)
    {
        m_sprite.SetPosition(-(int)img->GetWidth(), rand()%2000);
        m_dir = normalize(sf::Vector2f(1, dir));
    }
    // rechts
    if (start == 3)
    {
        m_sprite.SetPosition(2000, rand()%2000);
        m_dir = normalize(sf::Vector2f(-1, dir));
    }

    /*if (rand()%2 == 0)
    {
        m_dir.x*=-1.f;
    }
    if (rand()%2 == 0)
    {
        m_dir.y*=-1.f;
    }*/
}

asteroid::~asteroid()
{
}

void asteroid::update (float timeLastFrame)
{
    m_sprite.Move(m_dir*timeLastFrame*100.0f);
}

void asteroid::render ()
{
    m_rw->Draw(m_sprite);
}
