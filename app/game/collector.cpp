#include "collector.hpp"
#include "useful.hpp"
#include <iostream>

collector::collector(sf::Vector2f pos, sf::Image *img, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color col, planet *home)
    : ship(pos, img, rw, col)
    , m_imgBubble(imgBubble)  
    , m_goToPl(0)
    , m_goToAs(0)
    , m_goToBu(0)
    , m_home(home)
    , m_state(manualPositionGoTo)
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
    if (m_goToBu)
    {
        if (m_goToBu->getCollector() == this)
        {
            m_goToBu->setCollector(0);
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
        if (length(m_home->pos() - pos()) < collector::g_radius + planet::radius() + 40.0f)
        {
            if (m_goToAs)
            {
                m_home->addIron(10);
                delete m_goToAs;
                setState(lookingForAsteroid);
                m_goToAs = 0;
            }
            if (m_goToBu && m_goToPl)
            {
                m_home->addWater(10);
                delete m_goToBu;
                setState(lookingForPlanet);
                m_goToBu = 0;
            }
            if (m_goToBu && !m_goToPl)
            {
                m_home->addWater(10);
                delete m_goToBu;
                setState(lookingForWater);
                m_goToBu = 0;
            }
        }
    }
    if (m_state == lookingForPlanet)
    {
        if (!m_goToPl)
        {
            std::cerr << "MUST NOT HAPPEN !m_goToPl\n";
            return;
        }
        ship::goTo(m_goToPl->pos());
        if (length(m_goToPl->pos() - pos()) < bubble::size() + planet::radius() + 40.0f)
        {
            if (m_goToPl->water() > 0)
            {
                bubble *bub = new bubble(pos(), m_imgBubble, m_rw);
                bub->setCollector(this);
                m_goToBu = bub;
                m_goToPl->subWater(10);
                setState(gettingHome);
            }
            else
            {
                setState(manualPositionGoTo);
            }
        }
    }
    if (m_state == lookingForWater)
    {
        if (find(bubble::g_bubbles, m_goToBu) != 0 && m_goToBu->getCollector() == 0)
        {
            ship::goTo(m_goToBu->pos());
            if (length(m_goToBu->pos() - pos()) < collector::g_radius + bubble::size())
            {
                setState(gettingHome);
                m_goToBu->setCollector(this);
            }
        }
        else
        {
            m_goToBu = findNearestBubble();
        }
    }
    ship::update(timeLastFrame);
}

void collector::goTo(sf::Vector2f goTo)
{
    // is it an asteroid?
    if (m_goToAs)
        m_goToAs->setCollector(0);
    if (m_goToBu)
        m_goToBu->setCollector(0);
    m_goToAs = 0;
    m_goToBu = 0;
    m_goToPl = 0;
    m_state = manualPositionGoTo;
    asteroid * find = findByPos<asteroid>(asteroid::g_asteroids, goTo);
    if (find)
    {
        setState(lookingForAsteroid);
        m_goToAs = find;
    }
    else
    {
        bubble * find2 = findByPos<bubble>(bubble::g_bubbles, goTo);
        if (find2)
        {
            setState(lookingForWater);
            m_goToBu = find2;
        }
        else
        {
            planet * find3 = findByPos<planet>(planet::g_planets, goTo);
            if (find3 && find3 != m_home)
            {
                setState(lookingForPlanet);
                m_goToPl = find3;
            }
        }
    }
    if (m_state == manualPositionGoTo)
        ship::goTo(goTo);
}

void collector::getWater(planet *pl)
{
    goTo(pl->pos());
}

collector::state collector::getState()
{
    return m_state;
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

bubble* collector::findNearestBubble()
{
    bubble* res = 0;
    float dist = 1000000.0f;
    for (std::vector<bubble*>::iterator it = bubble::g_bubbles.begin(); it < bubble::g_bubbles.end(); ++it)
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

