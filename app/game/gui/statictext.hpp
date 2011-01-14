#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

class staticText : public widget
{
public:
    staticText (sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw);

    void render();

    void setCaption(std::string text);
private:
    sf::String m_caption;
};

#endif // STATICTEXT_HPP
