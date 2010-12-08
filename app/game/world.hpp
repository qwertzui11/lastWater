#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>

class world
{
public:
    world();
    ~world();

    void initialise();
private:
    sf::Image m_image;
};

#endif // WORLD_HPP
