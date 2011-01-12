#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"
#include "gui/button.hpp"

class human : public player
{
public:
    human(sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color colour);

    void event(const sf::Event *ev);

    void update(float timeLastFrame);
    void render();
private:
    void startSelect();
    void stopSelect();
    void sendSelected();

    sf::Shape *m_select;
    button m_btnAttacker;
    // button m_btnCollector;
};

#endif // HUMAN_HPP
