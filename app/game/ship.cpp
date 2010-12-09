#include "ship.hpp"
#include "useful.hpp"
#include <iostream>

std::vector<ship*> ship::g_ships;

ship::ship(sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : m_rw(rw)
    , m_sprite(*img)
    , m_goTo(0.f, 0.f)
{
    m_sprite.SetColor(col);
    g_ships.push_back(this);
}

ship::~ship()
{
    for (std::vector<ship*>::iterator it = g_ships.begin(); it < g_ships.end(); ++it)
    {
        if ((*it) == this)
        {
            g_ships.erase(it);
            break;
        }
    }
}

void ship::render()
{
    m_rw->Draw(m_sprite);
}

void ship::update(float timeLastFrame)
{
    sf::Vector2f wantedDir = normalize(m_goTo - m_sprite.GetPosition());
    wantedDir *= 300.0f;

    for (std::vector<ship*>::iterator it = g_ships.begin(); it < g_ships.end(); ++it)
    {
        if ((*it) == this)
            continue;
        sf::Vector2f otherPos = (*it)->pos();
        sf::Vector2f otherDir = otherPos - pos();
        if (length(otherDir) < g_radius*2.f)
        {
            sf::Vector2f inv = sf::Vector2f(1.f/otherDir.x, 1.f/otherDir.y);
            wantedDir-=inv*10000.f;
        }
    }

    m_sprite.Move(wantedDir * timeLastFrame);
}

void ship::goTo(sf::Vector2f goTo)
{
    m_goTo = goTo;
}

sf::Vector2f ship::pos()
{
    return m_sprite.GetPosition() + m_sprite.GetCenter();
}
