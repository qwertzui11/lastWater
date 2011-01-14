#include "stateManager.hpp"
#include <SFML/Window/Event.hpp>

stateManager::stateManager(state *start, sf::RenderWindow *rw)
    : m_rw(rw)
{
    m_current = start;
    m_current->setListener(this);
}

stateManager::~stateManager()
{
    ;
}

void stateManager::done (state *from, state *next)
{
    delete from;
    m_current = next;
    if (next == 0)
    {
        m_rw->Close();
    }
    else
        next->setListener(this);
}

int stateManager::run()
{
    while (m_rw->IsOpened())
    {
        sf::Event Event;
        while (m_rw->GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                m_rw->Close();
            if (m_current)
            {
                bool proccedEvent = m_current->event(&Event);
                (void)proccedEvent;
            }
            if (Event.Type == sf::Event::Resized)
                m_rw->GetDefaultView().SetHalfSize((float)Event.Size.Width, (float)Event.Size.Height);
        }
        m_rw->Clear();
        float frameTime = m_rw->GetFrameTime();
        if (frameTime > 1.f/60.f)
            frameTime = 1.f/60.f;
        if (m_current)
        {
            m_current->update(frameTime);
            m_current->render();
        }
        m_rw->Display();
    }
    return EXIT_SUCCESS;
}
