#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "statictext.hpp"
#include <SFML/Window/Event.hpp>

class button : public staticText
{
public:
    button(sf::FloatRect posAndSize, std::string text);

    void update(float time);
    void render();

    void insertEvent(sf::Event *event);
};

#endif // BUTTON_HPP
