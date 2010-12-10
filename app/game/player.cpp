#include "player.hpp"

player::player(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : m_rw(rw)
    , m_imgCollector(imgCollector)
    , m_imgAttacker(imgAttacker)
    , m_colour(colour)
    , m_pos(pos)
{
}

player::~player()
{

}

collector* player::newCollector()
{
    collector *newOne = new collector(m_pos, m_imgCollector, m_rw, m_colour);
    newOne->goTo(sf::Vector2f(m_pos.x, m_pos.y));
    m_collector.push_back(newOne);
    return newOne;
}

void player::update(float time)
{
    for(std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        (*it)->update(time);
    }
}

void player::render()
{
    for(std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        (*it)->render();
    }
}
