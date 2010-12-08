#include "world.hpp"

world::world(sf::RenderWindow *rw)
    : m_rw(rw)
{
}

world::~world()
{
}

void world::initialise()
{
    if (!m_image.LoadFromFile("../data/img/background.tga"))
    {
        return;
    }

    m_sprite.SetImage(m_image);

    m_sprite.SetX(0);
    m_sprite.SetY(0);
}

void world::render()
{
    m_rw->Draw(m_sprite);
}
