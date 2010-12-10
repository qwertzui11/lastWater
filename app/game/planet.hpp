#ifndef PLANET_HPP
#define PLANET_HPP

#include "SFML/Graphics.hpp"

class planet
{
public:
    planet(sf::Image *img, sf::RenderWindow *rw, sf::Vector2f pos, sf::Vector2f cpos, sf::Color col);

    void update(float time);
    void render();

    void addWater(int lvl);
    void addIron(int lvl);
    void subWater(int lvl);
    void subIron(int lvl);

private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_pos;
    sf::Vector2f m_cpos;
    int m_waterLvl;
    int m_ironLvl;
};

#endif // PLANET_HPP
