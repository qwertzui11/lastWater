#include "computer.hpp"

computer::computer(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : player(pos, imgCollector, imgAttacker, imgBullet, imgWorld, rw, colour)
    , m_createShip(0.f)
{
}

void computer::update(float time){
    player::update(time);

    m_createShip+= time;
    if (m_createShip > 1.f)
    {
        m_createShip = 0.f;
        attacker *att = player::newAttacker();
        att->goTo(sf::Vector2f(1000.f, 1000.f));
    }

}

void computer::render()
{
    player::render();
}


