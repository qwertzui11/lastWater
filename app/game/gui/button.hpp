#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "statictext.hpp"
#include <SFML/Window/Event.hpp>

class button : public staticText
{
public:
    button(sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw);

    void update(float time);
    void render();

    void insertEvent(const sf::Event *event);

private:
    sf::RenderWindow *m_rw;

    sf::Shape m_btn;
    sf::Shape m_hover;
    sf::Shape m_pressed;
    sf::Shape *m_current;

    sf::FloatRect m_posAndSize;
};

#endif // BUTTON_HPP
