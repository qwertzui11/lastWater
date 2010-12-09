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

    for (std::vector<ship*>::iterator it = g_ships.begin(); it < g_ships.end(); ++it)
    {
        if ((*it) == this)
            continue;
        sf::Vector2f otherPos = (*it)->pos();
        if (length(otherPos - pos()) < g_radius*2.f)
        {
            std::cerr << "collision\n";
        }
    }

    m_sprite.Move((m_goTo - m_sprite.GetPosition()) * timeLastFrame);
}

void ship::goTo(sf::Vector2f goTo)
{
    m_goTo = goTo;
}

sf::Vector2f ship::pos()
{
    return m_sprite.GetPosition() + m_sprite.GetCenter();
}
