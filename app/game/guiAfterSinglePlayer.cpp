#include "guiAfterSinglePlayer.hpp"

guiAfterSinglePlayer::guiAfterSinglePlayer(float worldSize, sf::RenderWindow *rw)
    : m_rw(rw)
    , m_status(sf::FloatRect(worldSize/2.f-150.f, worldSize/2.f-110.f, worldSize/2.f+150.f, worldSize/2.f-70.f), "status", m_rw)
    , m_restart (sf::FloatRect(worldSize/2.f-150.f, worldSize/2.f-50.f, worldSize/2.f+150.f, worldSize/2.f-10.f), "Restart", m_rw)
    , m_exit (sf::FloatRect(worldSize/2.f-150.f, worldSize/2.f+10.f, worldSize/2.f+150.f, worldSize/2.f+50.f), "Exit", m_rw)
    , m_activ(false)
    , m_statusStatus(pause)
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
    m_status.render();
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

void guiAfterSinglePlayer::setStatus (status st)
{
    m_statusStatus = st;
    if (st == lost)
    {
        m_status.setCaption("You Lost");
    }
    if (st == won)
    {
        m_status.setCaption("You Lost");
    }
    if (st == pause)
    {
        m_status.setCaption("Pause");
    }
}

