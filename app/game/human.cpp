#include "human.hpp"
#include <iostream>

human::human(sf::RenderWindow *rw, sf::Color colour)
    : player(rw, colour)
    , m_select(0)
{
}

void human::event(const sf::Event *ev)
{
    if (ev->Type == sf::Event::MouseButtonPressed)
        startSelect();

    if (ev->Type == sf::Event::MouseButtonReleased)
        stopSelect();
}

void human::update(float timeLastFrame)
{
    if (m_select)
    {
        sf::Vector2f pos = mousePos(m_rw);
        m_select->SetPointPosition(1, pos.x, m_select->GetPointPosition(0).y);
        m_select->SetPointPosition(3, m_select->GetPointPosition(0).x, pos.y);
        m_select->SetPointPosition(2, pos.x, pos.y);
    }
}

void human::render()
{
    if (m_select)
        m_rw->Draw(*m_select);
}

void human::startSelect()
{
    if (m_select)
        stopSelect();
    sf::Vector2f pos = mousePos(m_rw);
    m_select = new sf::Shape();
    *m_select = sf::Shape::Rectangle(pos.x+0, pos.y+0, pos.x+1, pos.y+1, sf::Color(255, 0, 0, 50), 2.0f, sf::Color::Green);
    //m_select->EnableFill(false);
}

void human::stopSelect()
{
    if (m_select)
    {
        delete m_select;
        m_select = 0;
    }
}