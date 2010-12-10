#include "planet.hpp"
#include <iostream>
#include <sstream>

planet::planet(sf::Image *img, sf::RenderWindow *rw, sf::Vector2f pos, sf::Vector2f cpos, sf::Color col, int waterLvl, int ironLvl, int type, float textX, float textY)
    : m_rw(rw)
    , m_sprite(*img)
    , m_pos(pos)
    , m_cpos(cpos)
    , m_waterLvl(waterLvl)
    , m_ironLvl(ironLvl)
    , m_font()
    , m_type(type)
    , m_textX(textX)
    , m_textY(textY)
{
    m_sprite.SetColor(col);
    m_sprite.SetCenter(m_cpos);
    m_sprite.SetPosition(m_pos);
    if (!m_font.LoadFromFile("../data/font/pirulen.ttf", 30))
    {
         std::cout << "m_font.LoadFromFile";
    }
}

void planet::render()
{

    m_rw->Draw(m_sprite);

    std::string w;
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
    }
}

void planet::update(float time)
{
    m_sprite.SetRotation(m_sprite.GetRotation()+(1.0f*time));
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
