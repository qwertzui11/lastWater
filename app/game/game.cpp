#include "game.hpp"
#include <iostream>

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
    , m_test(0)
{

}

game::~game()
{
}


void game::initialise()
{
    if (!m_imgShip.LoadFromFile("../data/img/1p_collector.tga"))
    {
        std::cout << "m_imgShip.LoadFromFile";
    }

    m_test = new ship(&m_imgShip, &m_window);
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

            // if (Event.Type == sf::Event::MouseButtonPressed && m_test)
            if (m_test)
                m_test->goTo(sf::Vector2f(m_window.GetInput().GetMouseX(), m_window.GetInput().GetMouseY()));
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
    m_test->update(timeLastFrame);
}

void game::render()
{
    if (m_test)
        m_test->render();
}
