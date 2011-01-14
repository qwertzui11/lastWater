#include "computer.hpp"

computer::computer(sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color colour)
    : player(pos, imgWet, imgDry, font, imgCollector, imgAttacker, imgBullet, imgWorld, imgBubble, rw, colour)
    , m_createShip(0.f)
    , m_lastMostWater(1000.f, 1000.f)
{
}

void computer::update(float time){
    player::update(time);

    m_createShip+= time;
    if (m_createShip > 0.25f)
    {
        sf::Vector2f mostWater(1000.f, 1000.f);
        int water = 0;
        for (std::vector<planet*>::iterator it = planet::g_planets.begin(); it < planet::g_planets.end(); ++it)
        {
            if ((*it)->water() > water && (*it) != &m_planet)
            {
                mostWater = (*it)->pos();
                water = (*it)->water();
            }
        }

        if (m_lastMostWater != mostWater)
        {
            m_lastMostWater = mostWater;
            for (std::vector<attacker*>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
            {
                if (rand()%2 == 0)
                {
                    (*it)->goTo(mostWater);
                }
                else
                {
                    (*it)->goTo((*(planet::g_planets.begin()+(rand()%planet::g_planets.size())))->pos());
                }
            }
            for (std::vector<collector*>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
            {
                if ((*it)->getState() == collector::manualPositionGoTo)
                    (*it)->goTo(mostWater);
            }
        }

        m_createShip = 0.f;
        bool createAColl(false);
        if (m_collector.size() < 3)
            createAColl = true;
        /*else
            createAColl = rand()%3==0;*/
        else
        {
            if (m_attacker.size() == 0)
                ;
            else
            {
                if ((m_collector.size()*100)/m_attacker.size() < 50)
                    createAColl = true;
            }
        }
        if (createAColl)
        {
            collector *coll = player::newCollector();
            if (coll)
            {
                if (m_collector.size() > 3 && rand()%2 == 0)
                {
                    if (rand()%5 != 0)
                    {
                        coll->goTo(mostWater);
                    }
                    else
                    {
                        coll->setState(collector::lookingForWater);
                    }
                }
                else
                {
                    coll->setState(collector::lookingForAsteroid);
                }
            }
        }
        else
        {
            attacker *att = player::newAttacker();
            if (att)
            {
                //if (rand()%2 == 0)
                {
                    att->goTo(mostWater);
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


