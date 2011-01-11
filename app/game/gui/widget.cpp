#include "widget.hpp"

widget::widget(sf::FloatRect posAndSize, std::string text)
    : m_posAndSize(posAndSize)
{
    setText(text);
}

void widget::setText(std::string text)
{
    m_text.SetText(text);
}
