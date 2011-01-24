#include "statictext.hpp"

staticText::staticText(sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw)
    : widget(posAndSize, rw)
{
    m_caption.SetSize(30);
    m_caption.SetColor(sf::Color(255, 255, 255));
    setCaption(text);
}

void staticText::setColour(sf::Color col)
{
    m_caption.SetColor(col);
}

void staticText::setCaption(std::string text)
{
    m_caption.SetText(text);
    sf::Vector2f pos(m_posAndSize.Left, m_posAndSize.Top);
    sf::Vector2f size(m_posAndSize.GetWidth(), m_posAndSize.GetHeight());
    sf::Vector2f center = sf::Vector2f((m_caption.GetRect().Right - m_caption.GetRect().Left)/2.f,
                                       (m_caption.GetRect().Bottom - m_caption.GetRect().Top)/2.f);
    sf::Vector2f res = pos + size/2.f - center;
    m_caption.SetPosition(res);
}

void staticText::render()
{
    sf::Color buffer = m_caption.GetColor();
    m_caption.SetColor(sf::Color(0,0,0));
    m_rw->Draw(m_caption);
    m_caption.SetPosition(m_caption.GetPosition()+sf::Vector2f(2.f, 2.f));
    m_caption.SetColor(buffer);
    m_rw->Draw(m_caption);
    m_caption.SetPosition(m_caption.GetPosition()-sf::Vector2f(2.f, 2.f));
}

