#include "asteroid.hpp"
#include "useful.hpp"
#include "collector.hpp"

#include <iostream>

std::vector <asteroid*> asteroid::g_asteroids;

asteroid::asteroid(sf::Image *img, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_sprite(*img)
    , m_collector(0)
{
    m_sprite.SetCenter(m_sprite.GetSize().x/2.f, m_sprite.GetSize().y/2.f);
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

    g_asteroids.push_back(this);
}

asteroid::~asteroid()
{
    findAndDelete<asteroid>(&g_asteroids, this);
}

void asteroid::update (float timeLastFrame)
{
    if (!m_collector)
        m_sprite.Move(m_dir*timeLastFrame*100.0f);
    else
        m_sprite.Move((m_collector->pos() - pos())*timeLastFrame*10.f);
}

void asteroid::render ()
{
    m_rw->Draw(m_sprite);
}

void asteroid::setCollector(collector *set)
{
    m_collector = set;
}

collector * asteroid::getCollector()
{
    return m_collector;
}
