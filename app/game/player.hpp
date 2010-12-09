#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "useful.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "attacker.hpp"
#include "collector.hpp"

class player
{
public:
    player(sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour);
    ~player();
protected:
    void newCollector();

    void update(float time);
    void render();

    sf::RenderWindow *m_rw;
    std::vector<attacker *> m_attacker;
    std::vector<collector *> m_collector;
private:
    sf::Image *m_imgCollector;
    sf::Image *m_imgAttacker;

    sf::Color m_colour;
};

#endif // PLAYER_HPP
