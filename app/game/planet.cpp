#include "planet.hpp"
#include <iostream>
#include <sstream>

std::vector<planet*> planet::g_planets;

planet::planet(sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::RenderWindow *rw, sf::Vector2f pos, sf::Color col, int waterLvl, int ironLvl)
    : m_rw(rw)
    , m_spriteWet(*imgWet)
    , m_spriteDry(*imgDry)
    , m_font(font)
    , m_pos(pos)
    , m_waterLvl(waterLvl)
    , m_ironLvl(ironLvl)
{
    (void)col;
    m_spriteDry.SetPosition(m_pos);
    m_spriteDry.SetCenter(m_spriteDry.GetSize().x/2.0f, m_spriteDry.GetSize().y/2.0f);
    m_spriteWet.SetPosition(m_pos);
    m_spriteWet.SetCenter(m_spriteWet.GetSize().x/2.0f, m_spriteWet.GetSize().y/2.0f);
    updateWater();
    g_planets.push_back(this);
}

planet::~planet()
{
    for (std::vector<planet*>::iterator it = g_planets.begin(); it < g_planets.end(); ++it)
    {
        if ((*it) == this)
        {
            g_planets.erase(it);
            break;
        }
    }
}

void planet::updateWater()
{
    m_spriteWet.SetColor(sf::Color(255, 255, 255, (m_waterLvl*255)/1000));
}

void planet::render()
{

    m_rw->Draw(m_spriteDry);
    m_rw->Draw(m_spriteWet);

    std::string w;
    std::stringstream wout;
    wout << m_waterLvl;
    w = wout.str();
    sf::String wText;
    wText.SetText("Water: "+w);
    wText.SetFont(*m_font);
    wText.SetSize(20);
    wText.SetColor(sf::Color(255, 255, 255));
    wText.SetScale(2.f, 2.f);
    wText.SetPosition(m_spriteDry.GetPosition() + sf::Vector2f(-wText.GetRect().GetWidth()/2.f, -10.0f-wText.GetRect().GetHeight()/2.f));
    m_rw->Draw(wText);

    if(m_ironLvl > -1)
    {
        std::string i;
        std::stringstream iout;
        iout << m_ironLvl;
        i = iout.str();
        sf::String iText;
        iText.SetText("Iron: "+i);
        iText.SetFont(*m_font);
        iText.SetSize(20);
        iText.SetColor(sf::Color(255, 255, 255));
        iText.SetScale(2.f, 2.f);
        iText.SetPosition(m_spriteDry.GetPosition() + sf::Vector2f(-iText.GetRect().GetWidth()/2.f, 10.0f+iText.GetRect().GetHeight()/2.f));
        m_rw->Draw(iText);
    }
}

void planet::update(float time)
{
    m_spriteDry.SetRotation(m_spriteDry.GetRotation()+(1.0f*time));
    m_spriteWet.SetRotation(m_spriteWet.GetRotation()+(1.0f*time));
}

void planet::addWater(int lvl)
{
    m_waterLvl += lvl;
    updateWater();
}

void planet::addIron(int lvl)
{
    if (m_ironLvl >= 0)
        m_ironLvl += lvl;
}

void planet::subWater(int lvl)
{
    m_waterLvl -= lvl;
    updateWater();
}

void planet::subIron(int lvl)
{
    m_ironLvl -= lvl;
}

int planet::iron()
{
    return m_ironLvl;
}

int planet::water()
{
    return m_waterLvl;
}
