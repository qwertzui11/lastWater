#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "player.hpp"

class computer : public player
{
public:
    computer(sf::Vector2f pos,
             sf::Image *imgWet,
             sf::Image *imgDry,
             sf::Font *font,
             sf::Image *imgCollector,
             sf::Image *imgAttacker,
             sf::Image *imgBullet,
             sf::Image *imgWorld,
             sf::Image *imgBubble,
             sf::RenderWindow *rw,
             sf::Color colour,
             sf::Image *imgExplosion);

    void update(float time);
    void render();

private:
    float m_createShip;

    sf::Vector2f m_lastMostWater;
};

#endif // COMPUTER_HPP
