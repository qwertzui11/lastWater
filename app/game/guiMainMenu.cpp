#include "guiMainMenu.hpp"
#include "game.hpp"

#include <SFML/Graphics/Rect.hpp>

guiMainMenu::guiMainMenu(sf::RenderWindow *rw)
    : m_rw(rw)
    , m_singleplayer(
            sf::FloatRect(m_rw->GetWidth() / 2.f - 100.f, m_rw->GetHeight() / 2.f - 20.f, m_rw->GetWidth() / 2.f + 100.f, m_rw->GetHeight() / 2.f + 20.),
            "SinglePlayer",
            rw)
    /*, m_tutorial()
    , m_credits()*/
    , m_exit(
            sf::FloatRect(m_rw->GetWidth() / 2.f - 100.f, m_rw->GetHeight() / 2.f + 40.f, m_rw->GetWidth() / 2.f + 100.f, m_rw->GetHeight() / 2.f + 80.),
            "Exit",
            rw)
{
    m_singleplayer.setListener(this);
    m_exit.setListener(this);
}

guiMainMenu::~guiMainMenu()
{
}

void guiMainMenu::clear()
{

}

void guiMainMenu::update(float time)
{
    (void)time;
}

void guiMainMenu::render()
{
    m_singleplayer.render();
    m_exit.render();
}


bool guiMainMenu::event(sf::Event *event)
{
    if (m_singleplayer.insertEvent(event))
        return false;
    if (m_exit.insertEvent(event))
        return false;
    return true;
}

void guiMainMenu::buttonPressed(button *btn)
{
    state *res(0);
    if (btn == &m_singleplayer)
    {
        res = new game(m_rw);
    }
    if (btn == &m_exit)
    {
        ;
    }
    done(res);
}
