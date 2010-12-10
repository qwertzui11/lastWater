#ifndef ATTACKER_HPP
#define ATTACKER_HPP

#include "ship.hpp"

class attacker : public ship
{
public:
    attacker(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col);
    ~attacker();

    void update(float time);
    void render();

    void kill();

    static std::vector<attacker*> g_attacker;

    float m_lastShot;
private:

};

#endif // ATTACKER_HPP
