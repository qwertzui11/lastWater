#include "game.hpp"
#include <iostream>

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
    , m_world(&m_window)
    , m_nextAsteroid(0.f)
    , m_player(sf::Vector2f(200.f, 200.f), &m_imgShip, &m_imgShip, 0, &m_window, sf::Color::Blue)
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
    sf::Vector2f m_cpos1p(200,200);
    m_1p = new planet(&m_img1p, &m_window, m_pos1p, m_cpos1p, sf::Color(230,185,117), 0, 0, 0, 100.f, 200.f);

    if (!m_img2p.LoadFromFile("../data/img/1p_planet.tga"))
    {
        std::cout << "m_img2p.LoadFromFile";
    }
    sf::Vector2f m_pos2p(1750,1750);
    sf::Vector2f m_cpos2p(200,200);
    m_2p = new planet(&m_img2p, &m_window, m_pos2p, m_cpos2p, sf::Color(230,185,117), 0, 0, 0, 1600.f, 1600.f);

    if (!m_imgWater.LoadFromFile("../data/img/water.tga"))
    {
        std::cout << "m_imgWater.LoadFromFile";
    }
    sf::Vector2f m_posWater(1000,1000);
    sf::Vector2f m_cposWater(250,247);
    m_water = new planet(&m_imgWater, &m_window, m_posWater, m_cposWater, sf::Color(32,167,225), 1000, 0, 1, 900.f, 1000.f);

    computer *newComp = new computer(sf::Vector2f(1800.f, 200.f), &m_imgShip, &m_imgShip, 0, &m_window, sf::Color::Cyan);
    m_computers.push_back(newComp);
    newComp = new computer(sf::Vector2f(200.f, 1800.f), &m_imgShip, &m_imgShip, 0, &m_window, sf::Color::Red);
    m_computers.push_back(newComp);
    newComp = new computer(sf::Vector2f(1800.f, 1800.f), &m_imgShip, &m_imgShip, 0, &m_window, sf::Color::Green);
    m_computers.push_back(newComp);
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

            m_player.event(&Event);
        }
        m_window.Clear();
        update(m_window.GetFrameTime());
        render();
        m_window.Display();
    }
    return EXIT_SUCCESS;
}

void game::update(float timeLastFrame)
{
    updateScroll(timeLastFrame);
    m_player.update(timeLastFrame);
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->update(timeLastFrame);
    }

    m_nextAsteroid+=timeLastFrame;
    if (m_nextAsteroid > 1.f)
    {
        m_nextAsteroid = 0.f;
        m_asteroids.push_back(new asteroid(&m_imgAsteroid, &m_window));
    }

    m_1p->update(timeLastFrame);
    m_2p->update(timeLastFrame);
    m_water->update(timeLastFrame);
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
        m_1p->render();
    if(m_2p)
        m_2p->render();
    if(m_water)
        m_water->render();
    for (std::vector<computer *>::iterator it = m_computers.begin(); it < m_computers.end(); ++it)
    {
        (*it)->render();
    }
    m_player.render();
}

void game::updateScroll(float time)
{
    if (m_window.GetInput().GetMouseX() < 20 || m_window.GetInput().IsKeyDown(sf::Key::Left))
    {
        m_viewPos.x-=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseX() > m_window.GetWidth()-20 || m_window.GetInput().IsKeyDown(sf::Key::Right))
    {
        m_viewPos.x+=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseY() < 20 || m_window.GetInput().IsKeyDown(sf::Key::Up))
    {
        m_viewPos.y-=g_scrollSpeed*time;
    }
    if (m_window.GetInput().GetMouseY() > m_window.GetHeight()-10 || m_window.GetInput().IsKeyDown(sf::Key::Down))
    {
        m_viewPos.y+=g_scrollSpeed*time;
    }
    if (m_viewPos.x - m_window.GetDefaultView().GetHalfSize().x < 0)
        m_viewPos.x = m_window.GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y - m_window.GetDefaultView().GetHalfSize().y < 0)
        m_viewPos.y = m_window.GetDefaultView().GetHalfSize().y;

    if (m_viewPos.x + m_window.GetDefaultView().GetHalfSize().x > 2000)
        m_viewPos.x = 2000-m_window.GetDefaultView().GetHalfSize().x;
    if (m_viewPos.y + m_window.GetDefaultView().GetHalfSize().y > 2000)
        m_viewPos.y = 2000-m_window.GetDefaultView().GetHalfSize().y;
    m_window.GetDefaultView().SetCenter(m_viewPos);
}

