#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "statictext.hpp"
#include <SFML/Window/Event.hpp>
#include "buttonListener.hpp"

class button : public staticText
{
public:
    button(sf::FloatRect posAndSize, std::string text, sf::RenderWindow *rw);

    void update(float time);
    void render();

    bool insertEvent(const sf::Event *event);

    void setListener(buttonListener *listener);

    bool hover();
private:
    sf::Shape m_btn;
    sf::Shape m_hover;
    sf::Shape m_pressed;
    sf::Shape *m_current;

    sf::FloatRect m_posAndSize;

    buttonListener *m_listener;
};

#endif // BUTTON_HPP
