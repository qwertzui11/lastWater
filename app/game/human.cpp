#include "human.hpp"
#include <iostream>

human::human(sf::RenderWindow *rw, sf::Color colour)
    : player(rw, colour)
{
}

void human::event(const sf::Event *ev)
{
    if (ev->Type == sf::Event::MouseButtonPressed)
        std::cerr << "MouseButtonPressed";
    if (ev->Type == sf::Event::MouseButtonReleased)
        std::cerr << "MouseButtonReleased";
}

void human::update(float timeLastFrame)
{

}

void human::render()
{

}
