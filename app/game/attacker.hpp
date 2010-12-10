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
    void kill() {m_alive = false;}
    bool alive() {return m_alive;}

    static std::vector<attacker*> g_attacker;

    float m_lastShot;
private:
    bool m_alive;
};

#endif // ATTACKER_HPP
