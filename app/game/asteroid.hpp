#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "SFML/Graphics.hpp"

class collector;

class asteroid
{
public:
    asteroid(sf::Image *img, sf::RenderWindow *rw);
    ~asteroid();

    void update (float timeLastFrame);
    void render ();

    sf::Vector2f pos() {return m_sprite.GetPosition();}

    void setCollector(collector *set);
    collector * getCollector();

    static float size() {return 30.f;}
    static std::vector <asteroid*> g_asteroids;
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_dir;

    collector * m_collector;
};

#endif // ASTEROID_HPP
