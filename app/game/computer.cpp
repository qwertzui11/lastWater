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
        bool createAColl(false);
        if (m_collector.size() < 5)
            createAColl = true;
        /*else
            createAColl = rand()%3==0;*/
        else
        {
            if (m_attacker.size() == 0)
                ;
            else
            {
                if ((m_collector.size()*100)/m_attacker.size() < 30)
                    createAColl = true;
            }
        }
        if (createAColl)
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
            {
                //if (rand()%2 == 0)
                {
                    att->goTo(sf::Vector2f(1000.f, 1000.f));
                }
                //else
                {
                //    att->goTo(m_planet.pos() + normalize(sf::Vector2f(1000.f, 1000.f) - m_planet.pos()) * 10.f);
                }
            }
        }
    }

}

void computer::render()
{
    player::render();
}


