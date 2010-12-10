#include "player.hpp"
#include "iostream"

player::player(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : m_rw(rw)
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
    attacker *newOne = new attacker(m_pos, m_imgAttacker, m_rw, m_colour);
    newOne->goTo(sf::Vector2f(m_pos.x+1.f, m_pos.y+1.f));
    m_attacker.push_back(newOne);
    return newOne;
}

collector* player::newCollector()
{
    collector *newOne = new collector(m_pos, m_imgCollector, m_rw, m_colour);
    newOne->goTo(sf::Vector2f(m_pos.x+1.f, m_pos.y+1.f));
    m_collector.push_back(newOne);
    return newOne;
}

void player::update(float time)
{
    // check for attack
    std::vector<attacker *> enemys;
    for(std::vector<attacker *>::iterator it = attacker::g_attacker.begin(); it < attacker::g_attacker.end(); ++it)
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
            enemys.push_back((*it));
        }
    }
    for(std::vector<attacker *>::iterator it2 = m_attacker.begin(); it2 < m_attacker.end(); ++it2)
    {
        for(std::vector<attacker *>::iterator it = enemys.begin(); it < enemys.end(); ++it)
        {
            if (length ((*it)->pos() - (*it2)->pos()) < 400.f)
            {
                if ((*it2)->m_lastShot <0.0f)
                {
                    (*it2)->m_lastShot = 0.5f;
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
        if ((*it)->lifeTime() > 3.f)
        {
            toDelete.push_back((*it));
            continue;
        }
        for(std::vector<attacker *>::iterator it2 = enemys.begin(); it2 < enemys.end(); ++it2)
        {
            if (length ((*it)->pos() - (*it2)->pos()) < attacker::g_radius)
            {
                toDelete.push_back((*it));

                if (rand()%2 == 0)
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
}
