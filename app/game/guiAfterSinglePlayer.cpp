#include "guiAfterSinglePlayer.hpp"

guiAfterSinglePlayer::guiAfterSinglePlayer(float worldSize, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_status(sf::FloatRect(worldSize/2.f-100.f, worldSize/2.f-20.f, worldSize/2.f+200.f, worldSize/2.f+40.f), "status", m_rw)
    , m_restart (sf::FloatRect(worldSize/2.f-100.f, worldSize/2.f-20.f, worldSize/2.f+200.f, worldSize/2.f+40.f), "Restart", m_rw)
    , m_exit (sf::FloatRect(100, 200, 100+200.f, 200+40.f), "Exit", m_rw)
    , m_activ(false)
{
    m_restart.setListener(this);
    m_exit.setListener(this);
}


bool guiAfterSinglePlayer::event(sf::Event *event)
{
    if (!m_activ)
        return true;
    if (m_restart.insertEvent(event))
        return false;
    if (m_exit.insertEvent(event))
        return false;
    return true;
}

void guiAfterSinglePlayer::update(float time)
{
    (void)time;
}

void guiAfterSinglePlayer::render()
{
    if (!m_activ)
        return;
    m_restart.render();
    m_exit.render();
}

void guiAfterSinglePlayer::clear()
{

}

void guiAfterSinglePlayer::buttonPressed(button *btn)
{
}

void guiAfterSinglePlayer::activate(bool activ)
{
    m_activ = activ;
    if (m_activ)
    {

    }
}
