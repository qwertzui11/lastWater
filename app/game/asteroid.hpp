#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "collectable.hpp"

class asteroid : public collectable
{
public:
    asteroid(float worldSize, sf::Image *img, sf::RenderWindow *rw);
    ~asteroid();

    void update (float timeLastFrame);

    static std::vector <asteroid*> g_asteroids;
private:
    sf::Vector2f m_dir;

    float m_rotSpeed;
};

#endif // ASTEROID_HPP
