#ifndef PLANET_HPP
#define PLANET_HPP

#include "SFML/Graphics.hpp"

class planet
{
public:
    planet(sf::Image *imgWet, sf::Image *imgDry, sf::Font *font, sf::RenderWindow *rw, sf::Vector2f pos, sf::Color col, int waterLvl, int ironLvl);
    ~planet();

    void update(float time);
    void render();

    void addWater(int lvl);
    void addIron(int lvl);
    void subWater(int lvl);
    void subIron(int lvl);

    int iron();
    int water();

    sf::Vector2f pos () {return m_pos;}

    static float radius() {return 200.f;}

    static std::vector<planet*> g_planets;
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_spriteWet;
    sf::Sprite m_spriteDry;
    sf::Font *m_font;

    sf::Vector2f m_pos;
    int m_waterLvl;
    int m_ironLvl;
};

#endif // PLANET_HPP
