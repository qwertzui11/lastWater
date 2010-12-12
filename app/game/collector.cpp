#include "collector.hpp"

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
    ship::update(timeLastFrame);
}

