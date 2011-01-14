#ifndef EXPLOSION_HPP
#define EXPLOSION_HPP

#include <SFML/Graphics.hpp>

class explosion
{
    public:
        explosion(sf::Vector2f pos,sf::Image *img, sf::RenderWindow *rw);

        void update(float time);
        void render();
        sf::Vector2f pos();
        float lifeTime();

    private:
        sf::IntRect m_explosion;
        sf::Sprite m_sprite;
        sf::RenderWindow *m_rw;
        float m_lifeTime;
        sf::Vector2f m_pos;
    };

#endif // EXPLOSION_HPP
