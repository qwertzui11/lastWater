#include "collector.hpp"
#include "useful.hpp"

collector::collector(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : ship(pos, img, rw, col)
    , m_state(manualPositionGoTo)
{

}

void collector::kill()
{
    if (rand()%40 == 0)
        m_alive = false;
}

void collector::update (float timeLastFrame)
{
    if (m_state == lookingForAsteroid)
    {
        if (find(asteroid::g_asteroids, m_goToAs) != 0)
        {
            goTo(m_goToAs->pos());
        }
        else
        {
            m_goToAs = findNearest();
        }
    }
    ship::update(timeLastFrame);
}

void collector::goTo(sf::Vector2f goTo)
{
    // is it an asteroid?
    asteroid * find = findByPos<asteroid>(asteroid::g_asteroids, goTo);
    if (find)
    {
        setState(lookingForAsteroid);
        m_goToAs = find;
    }
    ship::goTo(goTo);
}

void collector::setState(state set)
{
    m_goToAs = 0;
    m_goToPl = 0;
    m_state = set;
}

asteroid* collector::findNearest()
{
    asteroid* res = 0;
    float dist = 1000000.0f;
    for (std::vector<asteroid*>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        if (length((*it)->pos() - pos()) < dist)
        {
            res = (*it);
            dist = length((*it)->pos() - pos());
        }
    }
    return res;
}

