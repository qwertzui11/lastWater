#include "game.hpp"

game::game()
    : m_window(sf::VideoMode(1024, 768, 32), "lastWater")
    , m_client(&m_window)
{
}

game::~game()
{

}


void game::initialise()
{
    m_client.initialise();
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
            m_client.render();
        }
        m_window.Clear();
        m_window.Display();
    }
    return EXIT_SUCCESS;
}
