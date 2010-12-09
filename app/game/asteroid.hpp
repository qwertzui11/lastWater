#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "SFML/Graphics.hpp"

class asteroid
{
public:
    asteroid(sf::Image *img, sf::RenderWindow *rw);
    ~asteroid();

    void update (float timeLastFrame);
    void render ();

    sf::Vector2f pos() {return m_sprite.GetPosition();}
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_dir;
};

#endif // ASTEROID_HPP
