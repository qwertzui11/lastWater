#include "guiSinglePlayerSettings.hpp"
#include "game.hpp"

#include <sstream>

guiSinglePlayerSettings::guiSinglePlayerSettings(sf::RenderWindow *rw)
    : m_rw(rw)
{
    sf::Vector2f calc(rw->GetWidth()/2.f - 100.f, rw->GetHeight()/2.f - 50.f*(g_maxComputer/2.0f));
    for (int ind = 0; ind < g_maxComputer; ++ind)
    {
        button *newOne = new button(sf::FloatRect(calc.x, calc.y, calc.x+200.f, calc.y+40.f), "text", m_rw);
        std::ostringstream outStream;
        outStream << ind+1;
        std::string caption = outStream.str() + "x Enemys";
        newOne->setCaption(caption);
        newOne->setListener(this);
        m_numEnemys.push_back(newOne);
        calc+=sf::Vector2f(10.f, 50.f);
    }
}

bool guiSinglePlayerSettings::event(sf::Event *event)
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        if ((*it)->insertEvent(event))
            return false;
    return true;
}

void guiSinglePlayerSettings::update(float time)
{
    (void)time;
}

void guiSinglePlayerSettings::render()
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        (*it)->render();
}

void guiSinglePlayerSettings::clear()
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        delete (*it);
    m_numEnemys.clear();
}

void guiSinglePlayerSettings::buttonPressed(button *btn)
{
    int counter(0);
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
    {
        if ((*it) == btn)
        {
            done(new game(counter+1, m_rw));
            return;
        }
        ++counter;
    }
}
