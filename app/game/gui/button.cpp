#include "button.hpp"
#include "useful.hpp"

button::button(sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw)
    : staticText(posAndSize, text, rw)
    , m_btn(sf::Shape::Rectangle(
            posAndSize.Left, posAndSize.Top, posAndSize.Right, posAndSize.Bottom, sf::Color(255, 0, 0), 2.f, sf::Color(0, 0, 255)))
    , m_hover(sf::Shape::Rectangle(
            posAndSize.Left, posAndSize.Top, posAndSize.Right, posAndSize.Bottom, sf::Color(0, 255, 0), 2.f, sf::Color(255, 0, 0)))
    , m_pressed(sf::Shape::Rectangle(
            posAndSize.Left, posAndSize.Top, posAndSize.Right, posAndSize.Bottom, sf::Color(0, 255, 255), 2.f, sf::Color(255, 255, 0)))
    , m_current(&m_btn)
    , m_posAndSize(posAndSize)
    , m_listener(0)
{
}

void button::update(float time)
{
    (void)time;
}

void button::render()
{
    m_rw->Draw(*m_current);
    staticText::render();
}

bool button::insertEvent(const sf::Event *event)
{
    sf::Vector2f mPos = mousePos(m_rw);
    if (m_posAndSize.Contains(mPos.x, mPos.y))
    {
        m_current = &m_hover;
    }
    else
    {
        m_current = &m_btn;
        return false;
    }
    if (event->Type == sf::Event::MouseButtonPressed && m_current == &m_hover)
    {
        m_current = &m_pressed;
        return true;
    }
    if (event->Type == sf::Event::MouseButtonReleased && m_current == &m_hover)
    {
        m_current = &m_btn;
        m_listener->buttonPressed(this);
        return true;
    }
    return false;
}

void button::setListener(buttonListener *listener)
{
    m_listener = listener;
}

bool button::hover()
{
    return m_current == &m_hover;
}
