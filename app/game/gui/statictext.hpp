#ifndef STATICTEXT_HPP
#define STATICTEXT_HPP

#include "widget.hpp"

class staticText : public widget
{
public:
    staticText (sf::FloatRect posAndSize, std::string text);

    void render();
};

#endif // STATICTEXT_HPP
