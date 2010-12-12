#include "ship.hpp"
#include "useful.hpp"
#include <iostream>
#include "planet.hpp"

std::vector<ship*> ship::g_ships;

ship::ship(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col)
    : m_alive(true)
    , m_rw(rw)
    , m_sprite(*img)
    , m_goTo(0.f, 0.f)
    , m_selected(0)
{
    m_sprite.SetColor(col);
    m_sprite.SetPosition(pos);
    m_sprite.SetCenter(m_sprite.GetSize().x/2.0f, m_sprite.GetSize().y/2.0f);
    g_ships.push_back(this);
}

ship::~ship()
{
    for (std::vector<ship*>::iterator it = g_ships.begin(); it < g_ships.end(); ++it)
    {
        if ((*it) == this)
        {
            g_ships.erase(it);
            break;
        }
    }
}

void ship::render()
{
    m_rw->Draw(m_sprite);
    if (m_selected)
        m_rw->Draw(*m_selected);
}

void ship::update(float timeLastFrame)
{
    sf::Vector2f wantedDir = normalize(m_goTo - m_sprite.GetPosition());
    float distance = length(m_goTo - m_sprite.GetPosition());
    if (distance > 300.0f*timeLastFrame)
        wantedDir *= 300.0f;
    else
        wantedDir *= distance;

    // collidate with other ships
    for (std::vector<ship*>::iterator it = g_ships.begin(); it < g_ships.end(); ++it)
    {
        if ((*it) == this)
            continue;
        sf::Vector2f otherPos = (*it)->pos();
        sf::Vector2f otherDir = otherPos - pos();
        if (length(otherDir) < g_radius*2.f)
        {
            /*sf::Vector2f inv = sf::Vector2f(1.f/otherDir.x, 1.f/otherDir.y);
            wantedDir-=inv*5000.f;*/
            sf::Vector2f newPos = pos();
            otherDir = normalize(otherDir);
            newPos = otherPos - otherDir*g_radius*2.f;// + sf::Vector2f(5.f, 5.f);
            m_sprite.SetPosition(newPos/*-m_sprite.GetCenter()*/);
        }
    }

    m_sprite.Move(wantedDir * timeLastFrame);
    if (m_selected)
        m_selected->SetPosition(m_sprite.GetPosition());

    // collidate with planets
    for (std::vector<planet*>::iterator it = planet::g_planets.begin(); it < planet::g_planets.end(); ++it)
    {
        sf::Vector2f otherPos = (*it)->pos();
        sf::Vector2f otherDir = pos() - otherPos;
        if (length(otherDir) < g_radius+planet::radius())
        {
            sf::Vector2f newPos = pos();
            otherDir = normalize(otherDir);
            newPos = otherPos + otherDir*(g_radius+planet::radius());
            m_sprite.SetPosition(newPos/* - m_sprite.GetCenter()*/);
            break;
        }
    }
}

void ship::goTo(sf::Vector2f goTo)
{
    m_goTo = goTo;
}

sf::Vector2f ship::pos()
{
    return m_sprite.GetPosition();/* + m_sprite.GetCenter();*/
}

void ship::setSelected(bool sel)
{
    if (m_selected && sel)
        return;
    if (m_selected || !sel)
    {
        delete m_selected;
        m_selected=0;
    }
    if (sel)
    {
        m_selected = new sf::Shape();
        *m_selected = sf::Shape::Circle(0.f, 0.f, g_radius*1.5f, sf::Color::Magenta, 2.f, sf::Color::Magenta);
        m_selected->EnableFill(false);
    }
}

bool ship::isSelected()
{
    return m_selected != 0;
}

sf::FloatRect ship::collRect()
{
    return sf::FloatRect(m_sprite.GetPosition().x,
                             m_sprite.GetPosition().y,
                             m_sprite.GetPosition().x+m_sprite.GetSize().x,
                             m_sprite.GetPosition().y+m_sprite.GetSize().y);
}


