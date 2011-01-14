#include "asteroid.hpp"
#include "useful.hpp"
#include "collector.hpp"

#include <iostream>

std::vector <asteroid*> asteroid::g_asteroids;

asteroid::asteroid(float worldSize, sf::Image *img, sf::RenderWindow *rw)
    : collectable(img, rw)
{
    int size = worldSize;
    // kommt der asteroid von oben?
    int start = rand()%4;
    float dir = (rand()%size)-1000;
    dir/=1000.f;
    if (start == 0)
    {
        m_sprite.SetPosition(rand()%size, -(int)img->GetHeight());
        m_dir = normalize(sf::Vector2f(dir, 1));
    }
    // unten
    if (start == 1)
    {
        m_sprite.SetPosition(rand()%size, size);
        m_dir = normalize(sf::Vector2f(dir, -1));
    }
    // links
    if (start == 2)
    {
        m_sprite.SetPosition(-(int)img->GetWidth(), rand()%size);
        m_dir = normalize(sf::Vector2f(1, dir));
    }
    // rechts
    if (start == 3)
    {
        m_sprite.SetPosition(size, rand()%size);
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
        collectable::update(timeLastFrame);
}


