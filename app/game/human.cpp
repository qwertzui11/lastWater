#include "human.hpp"
#include <iostream>

human::human(sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color colour)
    : player(pos, imgWet, imgDry, font, imgCollector, imgAttacker, imgBullet, imgWorld, imgBubble, rw, colour)
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
    if (ev->Type == sf::Event::KeyReleased)
        if (ev->Key.Code == 'a')
            newAttacker();
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

        sf::FloatRect coll(m_select->GetPointPosition(0).x, m_select->GetPointPosition(0).y, pos.x, pos.y);
        if (coll.GetWidth() == 0)
            coll.Right = coll.Left+1.0f;
        if (coll.GetHeight() == 0)
            coll.Bottom = coll.Top+1.0f;

        bool gotOneAttacker(false);
        for (std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
        {
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
                gotOneAttacker = true;
                (*it)->setSelected(true);
            }
            else
            {
                (*it)->setSelected(false);
            }
        }
        for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
        {
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
            if (coll.Intersects((*it)->collRect()) && !gotOneAttacker)
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
    bool gotAnAttacker(false);
    for (std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
    {
        if ((*it)->isSelected())
        {
            gotAnAttacker = true;
            ++num;
        }
    }

    for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
    {
        if ((*it)->isSelected())
        {
            ++num;
        }
    }

    float sqrtNum = sqrt(num);
    int ind = 0;
    if (gotAnAttacker)
    {
        for (std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
        {
            if ((*it)->isSelected())
            {
                sf::Vector2f to = mousePos(m_rw);
                to += sf::Vector2f((-sqrtNum/2.f + ((float)(ind%(int)(sqrtNum+1))))*ship::g_radius*3.5f,
                                   (-sqrtNum/2.f + ((float)(ind/(int)(sqrtNum+1))))*ship::g_radius*3.5f);
                (*it)->goTo(to);
                ++ind;
            }
        }
    }
    else
    {
        for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
        {
            if ((*it)->isSelected())
            {
                sf::Vector2f to = mousePos(m_rw);
                /*to += sf::Vector2f((-sqrtNum/2.f + ((float)(ind%(int)(sqrtNum+1))))*ship::g_radius*3.5f,
                                   (-sqrtNum/2.f + ((float)(ind/(int)(sqrtNum+1))))*ship::g_radius*3.5f);*/
                (*it)->goTo(to);
                ++ind;
            }
        }
    }
}
