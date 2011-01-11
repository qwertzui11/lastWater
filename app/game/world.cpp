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

void world::update(float timeLastFrame)
{
    (void)timeLastFrame;
    /*const sf::View view = m_rw->GetView();
    m_sprite.SetX(view.GetCenter().x - view.GetHalfSize().x);
    m_sprite.SetY(view.GetCenter().y - view.GetHalfSize().y);*/
}

void world::render()
{
    m_rw->Draw(m_sprite);
}
