#include "attacker.hpp"

std::vector<attacker*> attacker::g_attacker;

attacker::attacker(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : ship(pos, img, rw, col)
    , m_lastShot(0.f)
    , m_alive(true)
{
    g_attacker.push_back(this);
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

