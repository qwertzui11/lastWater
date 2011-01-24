#include "world.hpp"

world::world(sf::RenderWindow *rw)
    : m_rw(rw)
{
}

world::~world()
{
}

void world::initialise(float worldSize)
{
    if (!m_image.LoadFromFile("../data/img/background.tga"))
    {
        return;
    }
    m_image.SetSmooth(false);
    m_sprite.SetImage(m_image);
    m_border[0] = sf::Shape::Line(sf::Vector2f(10, 10), sf::Vector2f(worldSize - 10, 10), 5.f, sf::Color::Red);
    m_border[1] = sf::Shape::Line(sf::Vector2f(worldSize - 10, 10), sf::Vector2f(worldSize - 10, worldSize - 10), 5.f, sf::Color::Red);
    m_border[2] = sf::Shape::Line(sf::Vector2f(worldSize - 10, worldSize - 10), sf::Vector2f(10, worldSize - 10), 5.f, sf::Color::Red);
    m_border[3] = sf::Shape::Line(sf::Vector2f(10, worldSize - 10), sf::Vector2f(10, 10), 5.f, sf::Color::Red);
/*    int cntx = m_worldSize / 1000;
    int cnty = m_worldSize / 625;
    for (int y=0; y<cnty+1; y++)
        for (int x=0; x<cntx+1; x++)
        {
            m_sprite.SetPosition(x*1000,y*625);
            m_rw->Draw(m_sprite);
        }
*/    //m_sprite.SetX(0);
    //m_sprite.SetY(0);

}

void world::update(float timeLastFrame)
{
    (void)timeLastFrame;
    /*const sf::View view = m_rw->GetView();
    m_sprite.SetX(view.GetCenter().x - view.GetHalfSize().x);
    m_sprite.SetY(view.GetCenter().y - view.GetHalfSize().y);*/
}

void world::render(float m_worldSize)
{
    int cntx = m_worldSize / 1245;
    int cnty = m_worldSize / 1245;
    for (int y=0; y<cnty+1; y++)
        for (int x=0; x<cntx+1; x++)
        {
            m_sprite.SetPosition(x*1245,y*1245);
            m_rw->Draw(m_sprite);
        }
    for (int ind =  0; ind < 4; ++ind)
        m_rw->Draw(m_border[ind]);
}
