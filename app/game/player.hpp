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
    player(sf::RenderWindow *rw, sf::Color colour);
    ~player();
protected:
    sf::RenderWindow *m_rw;
private:
    std::vector<attacker *> m_attacker;
    std::vector<collector *> m_collector;
};

#endif // PLAYER_HPP
