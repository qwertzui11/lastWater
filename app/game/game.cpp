#include "game.hpp"

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
{
}

game::initialise()
{
    m_client.initialise();
}

int game::run()
{
    while (App.IsOpened())
    {
        sf::Event Event;
        while (m_window.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                m_window.Close();
        }
        m_window.Clear();
        m_window.Display();
    }
    return EXIT_SUCCESS;
}
