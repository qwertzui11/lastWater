#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"

class human : public player
{
public:
    human(sf::Vector2f pos, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::RenderWindow *rw, sf::Color colour);

    void event(const sf::Event *ev);

    void update(float timeLastFrame);
    void render();
private:
    void startSelect();
    void stopSelect();
    void sendSelected();

    sf::Shape *m_select;

};

#endif // HUMAN_HPP
