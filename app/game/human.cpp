#include "human.hpp"
#include <iostream>
#include <sstream>

human::human(float worldSize, sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color colour, sf::Image *imgExplosion)
    : player(pos, imgWet, imgDry, font, imgCollector, imgAttacker, imgBullet, imgWorld, imgBubble, rw, colour, imgExplosion)
    , m_select(0)
    , m_btnAttacker(sf::FloatRect(pos.x+10, pos.y+90, pos.x + 180.f, pos.y + 130.f), "Attacker", m_rw)
    , m_btnCollector(sf::FloatRect(pos.x-180.f, pos.y+90, pos.x-10.f, pos.y + 130.f), "Collector", m_rw)
    , m_numNewCollector(1)
    , m_numNewAttacker(1)
    , m_worldSize(worldSize)
{
    updateButtonCaption();
    m_btnAttacker.setListener(this);
    m_btnCollector.setListener(this);
}

bool human::event(const sf::Event *ev)
{
    if (m_btnAttacker.insertEvent(ev))
    {return false;}
    if (m_btnCollector.insertEvent(ev))
    {return false;}

    if (ev->Type == sf::Event::MouseWheelMoved)
    {
        if (m_btnAttacker.hover())
        {
            m_numNewAttacker+=ev->MouseWheel.Delta;
            if (m_numNewAttacker<1)
                m_numNewAttacker=1;
            if (m_numNewAttacker>100)
                m_numNewAttacker=100;
            updateButtonCaption();
            return false;
        }
        if (m_btnCollector.hover())
        {
            m_numNewCollector+=ev->MouseWheel.Delta;
            if (m_numNewCollector<1)
                m_numNewCollector=1;
            if (m_numNewCollector>100)
                m_numNewCollector=100;
            updateButtonCaption();
            return false;
        }
    }

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

    return true;

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

        //bool gotOneAttacker(false);
        if (!m_rw->GetInput().IsKeyDown(sf::Key::LShift))
        {
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
            //        gotOneAttacker = true;
                    (*it)->setSelected(true);
                }
                else
                {
                    (*it)->setSelected(false);
                }
            }
        }
        if (!m_rw->GetInput().IsKeyDown(sf::Key::LControl))
        {
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
}

void human::render()
{
    player::render();
    if (m_select)
        m_rw->Draw(*m_select);
    m_btnAttacker.render();
    m_btnCollector.render();
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
//    bool gotAnAttacker(false);
    for (std::vector<attacker *>::iterator it = m_attacker.begin(); it < m_attacker.end(); ++it)
    {
        if ((*it)->isSelected())
        {
//            gotAnAttacker = true;
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
//    if (gotAnAttacker)
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
//    else
    {
        bool manual(true);
        for (std::vector<collector *>::iterator it = m_collector.begin(); it < m_collector.end(); ++it)
        {
            if ((*it)->isSelected())
            {
                sf::Vector2f to = mousePos(m_rw);

                if (it == m_collector.begin())
                {
                    (*it)->goTo(to);
                    if ((*it)->getState() == collector::manualPositionGoTo)
                        manual = false;
                }
                if (!manual)
                {
                    to += sf::Vector2f((-sqrtNum/2.f + ((float)(ind%(int)(sqrtNum+1))))*ship::g_radius*2.5f,
                                       (-sqrtNum/2.f + ((float)(ind/(int)(sqrtNum+1))))*ship::g_radius*2.5f);
                }
                (*it)->goTo(to);
                ++ind;
            }
        }
    }
}

void human::buttonPressed(button *btn)
{
    if (btn == &m_btnAttacker)
    {
        newAttacker();
    }
    if (btn == &m_btnCollector)
    {
        newCollector();
    }
}

void human::newAttacker()
{
    for (int ind = 0; ind < m_numNewAttacker; ++ind)
    {
        player::newAttacker();
    }
}

void human::newCollector()
{
    for (int ind = 0; ind < m_numNewCollector; ++ind)
    {
        player::newCollector();
    }
}

void human::updateButtonCaption()
{
    std::ostringstream outStream;
    outStream << m_numNewAttacker;
    std::string caption = outStream.str() + "x Attacker";
    m_btnAttacker.setCaption(caption);

    std::ostringstream outStream2;
    outStream2 << m_numNewCollector;
    caption = outStream2.str() + "x Collector";
    m_btnCollector.setCaption(caption);
}


