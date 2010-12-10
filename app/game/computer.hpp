#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "player.hpp"

class computer : public player
{
public:
    computer(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour);

    void update(float time);
    void render();

private:
    float m_createShip;
};

#endif // COMPUTER_HPP
