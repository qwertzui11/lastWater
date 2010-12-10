#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "useful.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "attacker.hpp"
#include "collector.hpp"
#include "bullet.hpp"

class player
{
public:
    player(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour);
    ~player();
protected:
    collector* newCollector();
    attacker* newAttacker();

    void update(float time);
    void render();

    sf::RenderWindow *m_rw;
    std::vector<attacker *> m_attacker;
    std::vector<collector *> m_collector;

    std::vector<bullet *> m_bullets;
private:
    sf::Image *m_imgCollector;
    sf::Image *m_imgAttacker;
    sf::Image *m_imgBullet;

    sf::Color m_colour;

    sf::Vector2f m_pos;
};

#endif // PLAYER_HPP
