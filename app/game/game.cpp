#include "game.hpp"
#include <iostream>

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
    , m_test(0)
    , m_world(&m_window)
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
    if (!m_imgAsteroid.LoadFromFile("../data/img/1p_fighter.tga"))
    {
        std::cout << "m_imgAsteroid.LoadFromFile";
    }

    m_test = new ship(&m_imgShip, &m_window);


    if (!m_img1p.LoadFromFile("../data/img/1p_planet.tga"))
    {
        std::cout << "m_img1p.LoadFromFile";
    }

    m_1p = new planet(&m_img1p, &m_window);

    if (!m_imgWater.LoadFromFile("../data/img/water.tga"))
    {
        std::cout << "m_imgWater.LoadFromFile";
    }

    m_water = new planet(&m_imgWater, &m_window);

    m_asteroids = new asteroid[20];
    for (int ind = 0; ind < 20; ++ind)
    {
        m_asteroids[ind] = asteroid(&m_imgAsteroid, &m_window);
    }

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

            if (Event.Type == sf::Event::MouseButtonPressed && m_test)
                m_test->goTo(sf::Vector2f(m_window.GetInput().GetMouseX() + m_window.GetView().GetCenter().x - m_window.GetWidth()/2,
                                          m_window.GetInput().GetMouseY() + m_window.GetView().GetCenter().y - m_window.GetHeight()/2));

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
                m_window.SetView(view2);
            }
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
    m_world.update(timeLastFrame);
    for (int ind = 0; ind < 20; ++ind)
    {
        m_asteroids[ind].update(timeLastFrame);
    }
    m_test->update(timeLastFrame);
}

void game::render()
{
    m_world.render();
    for (int ind = 0; ind < 20; ++ind)
    {
        m_asteroids[ind].render();
    }
    if (m_test)
        m_test->render();
}
