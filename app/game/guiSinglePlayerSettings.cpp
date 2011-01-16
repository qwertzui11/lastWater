#include "guiSinglePlayerSettings.hpp"
#include "game.hpp"

#include <sstream>

guiSinglePlayerSettings::guiSinglePlayerSettings(sf::RenderWindow *rw)
    : m_rw(rw)
    , m_exit(sf::FloatRect(rw->GetWidth() / 2.f - 350.f, rw->GetHeight() / 2.f + 40.f, m_rw->GetWidth() / 2.f + 100.f -250.f, rw->GetHeight() / 2.f + 80.f),
             "Exit",
             rw)
    , m_title("lastWater")
    , m_credits("by Markus Lanner & Andreas Fink")
{
    m_exit.setListener(this);

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

    sf::View * view = &m_rw->GetDefaultView();
    sf::FloatRect rect = view->GetRect();
    float width = m_rw->GetWidth();
    float height = m_rw->GetHeight();

    rect.Left = 0.f;
    rect.Top = 0.f;
    rect.Right=rect.Left+width;
    rect.Bottom=rect.Top+height;
    view->SetFromRect(rect);

    m_font.LoadFromFile("../data/font/pirulen.ttf", 50);

    m_title.SetPosition(rect.Left + width/2.f - 240.f, rect.Top + 10.f);
    m_credits.SetPosition(rect.Left + width/2.f - 240.f, rect.Top + 70.f);
    m_title.SetColor(sf::Color(255, 255, 255, 255));
    m_credits.SetSize(20);
    m_title.SetSize(50);

    m_title.SetFont(m_font);
}

bool guiSinglePlayerSettings::event(sf::Event *event)
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        if ((*it)->insertEvent(event))
            return false;
    return !m_exit.insertEvent(event);
}

void guiSinglePlayerSettings::update(float time)
{
    (void)time;
}

void guiSinglePlayerSettings::render()
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        (*it)->render();
    m_exit.render();
    m_rw->Draw(m_title);
    m_rw->Draw(m_credits);
}

void guiSinglePlayerSettings::clear()
{
    for (std::vector<button *>::iterator it = m_numEnemys.begin(); it < m_numEnemys.end(); ++it)
        delete (*it);
    m_numEnemys.clear();
}

void guiSinglePlayerSettings::buttonPressed(button *btn)
{
    if (btn == &m_exit)
    {
        done(0);
        return;
    }
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
