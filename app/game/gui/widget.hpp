#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/String.hpp>
#include <string>

class widget
{
public:
    widget(sf::FloatRect posAndSize, sf::RenderWindow *rw);

    void setText(std::string text);
protected:
    sf::FloatRect m_posAndSize;

    sf::RenderWindow *m_rw;
};

#endif // WIDGET_HPP
