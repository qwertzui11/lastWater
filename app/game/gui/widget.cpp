#include "widget.hpp"

widget::widget(sf::FloatRect posAndSize, sf::RenderWindow *rw)
    : m_posAndSize(posAndSize)
    , m_rw(rw)
{
}

