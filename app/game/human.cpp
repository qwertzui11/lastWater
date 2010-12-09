#include "human.hpp"
#include <iostream>

human::human(sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour)
    : player(imgCollector, imgAttacker, imgWorld, rw, colour)
    , m_select(0)
{
}

void human::event(const sf::Event *ev)
{
    if (ev->Type == sf::Event::MouseButtonPressed)
        if (ev->MouseButton.Button==sf::Mouse::Left)
            startSelect();

    if (ev->Type == sf::Event::MouseButtonReleased)
    {
        if (ev->MouseButton.Button==sf::Mouse::Left)
            stopSelect();
        if (ev->MouseButton.Button==sf::Mouse::Right)
            sendSelected();
    }


    if (ev->Type == sf::Event::KeyReleased)
        if (ev->Key.Code == 'c')
            newCollector();

}

void human::update(float timeLastFrame)
{
    player::update(timeLastFrame);
    if (m_select)
    {
        sf::Vector2f pos = mousePos(m_rw);
        m_select->SetPointPosition(1, pos.x, m_select->GetPointPosition(0).y);
        m_select->SetPointPosition(3, m_select->GetPointPosition(0).x, pos.y);
        m_select->SetPointPosition(2, pos.x, pos.y);

        for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
        {
            sf::FloatRect coll(m_select->GetPointPosition(0).x, m_select->GetPointPosition(0).y, pos.x, pos.y);
            if (pos.x < m_select->GetPointPosition(0).x)
            {
                coll.Left = pos.x;
                coll.Right = m_select->GetPointPosition(0).x;
            }
            if (pos.y < m_select->GetPointPosition(0).y)
            {
                coll.Top = pos.y;
                coll.Bottom = m_select->GetPointPosition(0).y;
            }
            if (coll.Intersects((*it)->collRect()))
            {
                (*it)->setSelected(true);
            }
            else
            {
                (*it)->setSelected(false);
            }
        }
    }
}

void human::render()
{
    player::render();
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
}

void human::stopSelect()
{
    if (m_select)
    {
        delete m_select;
        m_select = 0;
    }
}

void human::sendSelected()
{
    int num(0);
    for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        if ((*it)->isSelected())
        {
            (*it)->goTo(mousePos(m_rw));
        }
    }
}
