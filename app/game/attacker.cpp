#include "attacker.hpp"

std::vector<attacker*> attacker::g_attacker;

attacker::attacker(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : ship(pos, img, rw, col)
    , m_lastShot(0.f)
{
    g_attacker.push_back(this);
}

attacker::~attacker()
{
    for (std::vector<attacker*>::iterator it = g_attacker.begin(); it < g_attacker.end(); ++it)
    {
        if ((*it) == this)
        {
            g_attacker.erase(it);
            break;
        }
    }
}

void attacker::update(float time)
{
    ship::update(time);

    m_lastShot-=time;
}

void attacker::render()
{
    ship::render();
}

void attacker::kill()
{
    if (rand()%100 == 0)
        m_alive = false;
}

