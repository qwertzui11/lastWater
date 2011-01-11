#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/String.hpp>
#include <string>

class widget
{
public:
    widget(sf::FloatRect posAndSize, std::string text);

    void setText(std::string text);
protected:
    sf::FloatRect m_posAndSize;
    sf::String m_text;
};

#endif // WIDGET_HPP
