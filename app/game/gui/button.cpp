#include "button.hpp"

button::button(sf::FloatRect posAndSize, std::string text)
    : staticText(posAndSize, text)
{
}

void button::update(float time)
{
    (void)time;
}

void button::render()
{

}

void button::insertEvent(sf::Event *event)
{
    (void)event;
}
