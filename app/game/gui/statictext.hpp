#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

class staticText : public widget
{
public:
    staticText (sf::FloatRect posAndSize, std::string text);

    void render();
};

#endif // STATICTEXT_HPP
