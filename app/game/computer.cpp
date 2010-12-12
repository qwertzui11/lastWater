#include "computer.hpp"

computer::computer(sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : player(pos, imgWet, imgDry, font, imgCollector, imgAttacker, imgBullet, imgWorld, rw, colour)
    , m_createShip(0.f)
{
}

void computer::update(float time){
    player::update(time);

    m_createShip+= time;
    if (m_createShip > 0.25f)
    {
        m_createShip = 0.f;
        if (m_collector.size() < 5)
        {
            collector *coll = player::newCollector();
            if (coll)
            {
                coll->setState(collector::lookingForAsteroid);
            }
        }
        else
        {
            attacker *att = player::newAttacker();
            if (att)
                att->goTo(sf::Vector2f(1000.f, 1000.f));
        }
    }

}

void computer::render()
{
    player::render();
}


