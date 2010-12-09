#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"

class human : public player
{
public:
    human(sf::RenderWindow *rw, sf::Color colour);

    void event(const sf::Event *ev);

    void update(float timeLastFrame);
    void render();
private:
    sf::FloatRect m_select;
};

#endif // HUMAN_HPP
