#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "SFML/Graphics.hpp"

class asteroid
{
public:
    asteroid()  {;}
    asteroid(sf::Image *img, sf::RenderWindow *rw);

    void update (float timeLastFrame);
    void render ();
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_dir;
};

#endif // ASTEROID_HPP
