#include "player.hpp"
#include "iostream"

player::player(sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : m_rw(rw)
    , m_planet(imgWet, imgDry, font, rw, pos, colour, 0, 10)
    , m_imgCollector(imgCollector)
    , m_imgAttacker(imgAttacker)
    , m_imgBullet(imgBullet)
    , m_colour(colour)
    , m_pos(pos)
{
}

player::~player()
{

}

attacker* player::newAttacker()
{
    if (m_planet.iron() < 10)
        return 0;
    m_planet.subIron(10);

    attacker *newOne = new attacker(m_pos, m_imgAttacker, m_rw, m_colour);
    float ra = rand()%10000;
    ra/=1000.f;
    newOne->goTo(sf::Vector2f(m_pos.x+ra, m_pos.y+1.f));
    m_attacker.push_back(newOne);
    return newOne;
}

collector* player::newCollector()
{
    if (m_planet.iron() < 5)
        return 0;
    m_planet.subIron(5);

    collector *newOne = new collector(m_pos, m_imgCollector, m_rw, m_colour, &m_planet);
    float ra = rand()%10000;
    ra/=1000.f;
    newOne->goTo(sf::Vector2f(m_pos.x+ra, m_pos.y+1.f));
    m_collector.push_back(newOne);
    return newOne;
}

void player::update(float time)
{
    // check for attack
    std::vector<ship *> enemys;
    for(std::vector<ship *>::iterator it = ship::g_ships.begin(); it < ship::g_ships.end(); ++it)
    {
        bool in (false);
        for(std::vector<attacker *>::iterator it2 = m_attacker.begin(); it2 < m_attacker.end(); ++it2)
        {
            if ((*it2) == (*it))
            {
                in = true;
                break;
            }
        }
        if (!in)
        {
            for(std::vector<collector *>::iterator it2 = m_collector.begin(); it2 < m_collector.end(); ++it2)
            {
                if ((*it2) == (*it))
                {
                    in = true;
                    break;
                }
            }
        }
        if (!in)
        {
            enemys.push_back((*it));
        }
    }
    for(std::vector<attacker *>::iterator it2 = m_attacker.begin(); it2 < m_attacker.end(); ++it2)
    {
        if ((*it2)->m_lastShot <0.0f)
        {
            for(std::vector<ship *>::iterator it = enemys.begin(); it < enemys.end(); ++it)
            {
                if (length ((*it)->pos() - (*it2)->pos()) < 400.f)
                {
                    (*it2)->m_lastShot = 0.2f;
                    m_bullets.push_back(new bullet((*it2)->pos(), (*it)->pos() - (*it2)->pos(), m_imgBullet, m_rw, m_colour));
                    break;
                }
            }
        }
    }



    for(std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
    {
    //    (*it)->update(time);
        if (!(*it)->alive())
        {
            delete (*it);
            m_attacker.erase((it));
            break;
        }
    }
    for(std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
    //    (*it)->update(time);
        if (!(*it)->alive())
        {
            delete (*it);
            m_collector.erase((it));
            break;
        }
    }


    for(std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        (*it)->update(time);
    }
    for(std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
    {
        (*it)->update(time);
    }


    std::vector<bullet*> toDelete;

    for (std::vector<bullet *>::iterator it = m_bullets.begin(); it < m_bullets.end(); ++it)
    {
        (*it)->update(time);
        if ((*it)->lifeTime() > 1.f)
        {
            toDelete.push_back((*it));
            continue;
        }
        for(std::vector<ship *>::iterator it2 = enemys.begin(); it2 < enemys.end(); ++it2)
        {
            if (length ((*it)->pos() - (*it2)->pos()) < attacker::g_radius)
            {
                toDelete.push_back((*it));

                (*it2)->kill();

                break;
            }
        }
    }

    for (std::vector<bullet *>::iterator it = toDelete.begin(); it < toDelete.end(); ++it)
    {
        delete (*it);
        for (std::vector<bullet *>::iterator it2 = m_bullets.begin(); it2 < m_bullets.end(); ++it2)
        {
            if ((*it2) == (*it))
            {
                m_bullets.erase(it2);
                break;
            }
        }
    }
    toDelete.clear();

    m_planet.update(time);
}

void player::render()
{
    for (std::vector<bullet *>::iterator it = m_bullets.begin(); it < m_bullets.end(); ++it)
    {
        (*it)->render();
    }
    for(std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        (*it)->render();
    }
    for(std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
    {
        (*it)->render();
    }
    m_planet.render();
}
