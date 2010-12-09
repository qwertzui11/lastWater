#include "game.hpp"
#include <iostream>

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
    , m_world(&m_window)
    , m_nextAsteroid(0.f)
    , m_player(&m_imgShip, &m_imgShip, 0, &m_window, sf::Color::Blue)
{
}

game::~game()
{
}


void game::initialise()
{
    m_world.initialise();

    if (!m_imgShip.LoadFromFile("../data/img/1p_collector.tga"))
    {
        std::cout << "m_imgShip.LoadFromFile";
    }
    if (!m_imgAsteroid.LoadFromFile("../data/img/asteroid.tga"))
    {
        std::cout << "m_imgAsteroid.LoadFromFile";
    }

    if (!m_img1p.LoadFromFile("../data/img/1p_planet.tga"))
    {
        std::cout << "m_img1p.LoadFromFile";
    }
    sf::Vector2f m_pos1p(250,250);
    m_1p = new planet(&m_img1p, &m_window, m_pos1p, sf::Color(230,185,117));

    if (!m_imgWater.LoadFromFile("../data/img/water.tga"))
    {
        std::cout << "m_imgWater.LoadFromFile";
    }
    sf::Vector2f m_posWater(1200,1200);
    m_water = new planet(&m_imgWater, &m_window, m_posWater, sf::Color(32,167,225));
}

int game::run()
{
    while (m_window.IsOpened())
    {
        sf::Event Event;
        while (m_window.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                m_window.Close();

            if (Event.Type == sf::Event::MouseMoved)
            {
                const sf::View view = m_window.GetView();
                sf::View view2 = view;
                if (m_window.GetInput().GetMouseX() < 10)
                {
                    view2.Move(-10.f/**m_window.GetFrameTime()*/, 0.f);
                }
                if (m_window.GetInput().GetMouseX() > m_window.GetWidth()-10)
                {
                    view2.Move(10.f/**m_window.GetFrameTime()*/, 0.f);
                }
                if (m_window.GetInput().GetMouseY() < 10)
                {
                    view2.Move(0.f/**m_window.GetFrameTime()*/, -10.f);
                }
                if (m_window.GetInput().GetMouseY() > m_window.GetHeight()-10)
                {
                    view2.Move(0.f/**m_window.GetFrameTime()*/, 10.f);
                }
                if (view2.GetCenter().x - view.GetHalfSize().x < 0)
                    view2.SetCenter(view2.GetHalfSize().x, view.GetCenter().y);
                if (view2.GetCenter().y - view.GetHalfSize().y < 0)
                    view2.SetCenter(view.GetCenter().x, view.GetHalfSize().y);

                if (view2.GetCenter().x + view.GetHalfSize().x > 2000)
                    view2.SetCenter(2000-view2.GetHalfSize().x, view.GetCenter().y);
                if (view2.GetCenter().y + view.GetHalfSize().y > 2000)
                    view2.SetCenter(view.GetCenter().x, 2000-view.GetHalfSize().y);
                m_window.SetView(view2);
            }

            m_player.event(&Event);
        }
        // m_window.SetView();
        m_window.Clear();
        update(m_window.GetFrameTime());
        render();
        m_window.Display();
    }
    return EXIT_SUCCESS;
}

void game::update(float timeLastFrame)
{
    m_player.update(timeLastFrame);

    m_nextAsteroid+=timeLastFrame;
    if (m_nextAsteroid > 1.f)
    {
        m_nextAsteroid = 0.f;
        m_asteroids.push_back(new asteroid(&m_imgAsteroid, &m_window));
    }

    m_world.update(timeLastFrame);

    for (std::vector<asteroid *>::iterator it = m_asteroids.begin(); it < m_asteroids.end(); ++it)
    {
        (*it)->update(timeLastFrame);
        sf::Vector2f pos = (*it)->pos();
        if (pos.x > 2000.f || pos.y > 2000.f || pos.x + m_imgAsteroid.GetWidth() < 0.f || pos.y + m_imgAsteroid.GetHeight() < 0.f)
        {
            delete (*it);
            m_asteroids.erase(it);
            break;
        }
    }
}

void game::render()
{
    m_world.render();
    for (std::vector<asteroid *>::iterator it = m_asteroids.begin(); it < m_asteroids.end(); ++it)
    {
        (*it)->render();
    }
    if(m_1p)
        m_1p->render(sf::Vector2f(200,200));
    if(m_water)
        m_water->render(sf::Vector2f(250,247));
    m_player.render();
}
