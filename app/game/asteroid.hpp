#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "collectable.hpp"

class asteroid : public collectable
{
public:
    asteroid(sf::Image *img, sf::RenderWindow *rw);
    ~asteroid();

    void update (float timeLastFrame);

    static std::vector <asteroid*> g_asteroids;
private:
    sf::Vector2f m_dir;
};

#endif // ASTEROID_HPP
