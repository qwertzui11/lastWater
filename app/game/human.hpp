#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "player.hpp"
#include "gui/button.hpp"
#include "gui/buttonListener.hpp"

class human : public player, private buttonListener
{
public:
    human(float worldSize, sf::Vector2f pos, sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::Image *imgCollector, sf::Image *imgAttacker, sf::Image *imgBullet, sf::Image *imgWorld, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color colour, sf::Image *imgExplosion);

    bool event(const sf::Event *ev);

    void update(float timeLastFrame);
    void render();
private:
    void startSelect();
    void stopSelect();
    void sendSelected();

    void newAttacker();
    void newCollector();

    void buttonPressed(button *btn);
    void updateButtonCaption();

    sf::Shape *m_select;
    button m_btnAttacker;
    button m_btnCollector;

    int m_numNewCollector;
    int m_numNewAttacker;

    float m_worldSize;
};

#endif // HUMAN_HPP
