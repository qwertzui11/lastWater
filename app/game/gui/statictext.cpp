#include "statictext.hpp"

staticText::staticText(sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw)
    : widget(posAndSize, rw)
{
    m_caption.SetSize(20);
    m_caption.SetColor(sf::Color(255, 255, 255));
    setCaption(text);
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
    m_rw->Draw(m_caption);
}

