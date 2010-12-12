#include "planet.hpp"
#include <iostream>
#include <sstream>

std::vector<planet*> planet::g_planets;

planet::planet(sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::RenderWindow *rw, sf::Vector2f pos, sf::Color col, int waterLvl, int ironLvl)
    : m_rw(rw)
    , m_spriteWet(*imgWet)
    , m_spriteDry(*imgDry)
    , m_pos(pos)
    , m_waterLvl(waterLvl)
    , m_ironLvl(ironLvl)
    , m_font(font)
{
    m_spriteDry.SetPosition(m_pos);
    m_spriteDry.SetCenter(m_spriteDry.GetSize().x/2.0f, m_spriteDry.GetSize().y/2.0f);
    m_spriteWet.SetPosition(m_pos);
    m_spriteWet.SetCenter(m_spriteWet.GetSize().x/2.0f, m_spriteWet.GetSize().y/2.0f);
    m_spriteWet.SetColor(sf::Color(255, 255, 255, (m_waterLvl*255)/1000));

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

void planet::render()
{

    m_rw->Draw(m_spriteDry);
    m_rw->Draw(m_spriteWet);

    /*std::string w;
    std::stringstream wout;
    wout << m_waterLvl;
    w = wout.str();
    sf::String wText;
    wText.SetText("Water: "+w);
    wText.SetFont(m_font);
    wText.SetSize(20);
    wText.SetColor(sf::Color(255, 255, 255));
    wText.SetScale(2.f, 2.f);
    wText.Move(m_textX, m_textY);
    m_rw->Draw(wText);

    if(m_type == 0)
    {
        std::string i;
        std::stringstream iout;
        iout << m_ironLvl;
        i = wout.str();
        sf::String iText;
        iText.SetText("Iron: "+w);
        iText.SetFont(m_font);
        iText.SetSize(20);
        iText.SetColor(sf::Color(255, 255, 255));
        iText.SetScale(2.f, 2.f);
        iText.Move(m_textX, m_textY+50.f);
        m_rw->Draw(iText);
    }*/
}

void planet::update(float time)
{
    m_spriteDry.SetRotation(m_spriteDry.GetRotation()+(1.0f*time));
    m_spriteWet.SetRotation(m_spriteWet.GetRotation()+(1.0f*time));
}

void planet::addWater(int lvl)
{
    m_waterLvl += lvl;
}

void planet::addIron(int lvl)
{
    m_ironLvl += lvl;
}

void planet::subWater(int lvl)
{
    m_waterLvl -= lvl;
}

void planet::subIron(int lvl)
{
    m_ironLvl -= lvl;
}
