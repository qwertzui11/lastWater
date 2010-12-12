#ifndef COLLECTABLE_HPP
#define COLLECTABLE_HPP

#include "SFML/Graphics.hpp"

class collector;

class collectable
{
public:
    collectable(sf::Image *img, sf::RenderWindow *rw);
    ~collectable();

    void update (float timeLastFrame);
    void render ();

    sf::Vector2f pos() {return m_sprite.GetPosition();}

    void setCollector(collector *set);
    collector * getCollector();

    static float size() {return 30.f;}

protected:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    collector * m_collector;
};

#endif // COLLECTABLE_HPP
