#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

class world
{
public:
    world(sf::RenderWindow *rw);
    ~world();

    void initialise(float m_worldSize);
    void update(float );
    void render(float m_worldSize);

private:
    sf::RenderWindow *m_rw;
    sf::Image m_image;
    sf::Sprite m_sprite;
};

#endif // WORLD_HPP
