#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>

class bullet
{
public:
    bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Image *img, sf::RenderWindow *rw, sf::Color col);

    void update(float time);
    void render();

    sf::Vector2f pos();

    float lifeTime();

    static const float g_speed = 500.f;
private:
    sf::Sprite m_sprite;
    sf::Vector2f m_dir;

    sf::RenderWindow *m_rw;

    float m_lifeTime;

    sf::Sound m_sndBullet;
};

#endif // BULLET_HPP
