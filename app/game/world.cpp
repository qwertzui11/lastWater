#include "world.hpp"

world::world()
{
}

world::~world()
{
}

void world::initialise()
{
    if (!m_image.LoadFromFile("background.tga"))
    {
        return;
    }

    m_sprite.SetImage(m_image);

    m_sprite.SetX(100);
    m_sprite.SetY(100);
}
