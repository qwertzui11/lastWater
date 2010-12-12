#include "collector.hpp"
#include "useful.hpp"

collector::collector(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col, planet *home)
    : ship(pos, img, rw, col)
    , m_state(manualPositionGoTo)
    , m_home(home)
    , m_goToAs(0)
{

}

collector::~collector()
{
    if (m_goToAs)
    {
        if (m_goToAs->getCollector() == this)
        {
            m_goToAs->setCollector(0);
        }
    }
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
        if (find(asteroid::g_asteroids, m_goToAs) != 0 && m_goToAs->getCollector() == 0)
        {
            ship::goTo(m_goToAs->pos());
            if (length(m_goToAs->pos() - pos()) < collector::g_radius + asteroid::size())
            {
                setState(gettingHome);
                m_goToAs->setCollector(this);
            }
        }
        else
        {
            m_goToAs = findNearest();
        }
    }
    if (m_state == gettingHome)
    {
        ship::goTo(m_home->pos());
        if (length(m_home->pos() - pos()) < collector::g_radius + planet::radius() + 10.0f)
        {
            m_home->addIron(10);
            delete m_goToAs;
            setState(lookingForAsteroid);
            m_goToAs = 0;
        }
    }
    ship::update(timeLastFrame);
}

void collector::goTo(sf::Vector2f goTo)
{
    // is it an asteroid?
    asteroid * find = findByPos<asteroid>(asteroid::g_asteroids, goTo);
    if (find && m_state == manualPositionGoTo)
    {
        setState(lookingForAsteroid);
        m_goToAs = find;
    }
    if (m_state == manualPositionGoTo)
        ship::goTo(goTo);
}

void collector::setState(state set)
{
    /*if (m_state != lookingForAsteroid)
        m_goToAs = 0;
    m_goToPl = 0;*/
    m_state = set;
}

asteroid* collector::findNearest()
{
    asteroid* res = 0;
    float dist = 1000000.0f;
    for (std::vector<asteroid*>::iterator it = asteroid::g_asteroids.begin(); it < asteroid::g_asteroids.end(); ++it)
    {
        if ((*it)->getCollector() == 0)
        {
            if (length((*it)->pos() - pos()) < dist)
            {
                res = (*it);
                dist = length((*it)->pos() - pos());
            }
        }
    }
    return res;
}

