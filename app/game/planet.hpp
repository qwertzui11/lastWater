#ifndef PLANET_HPP
#define PLANET_HPP

#include "SFML/Graphics.hpp"

class planet
{
public:
    planet(sf::Image *img, sf::RenderWindow *rw, sf::Vector2f pos, sf::Vector2f cpos, sf::Color col, int waterLvl, int ironLvl, int type, float textX, float textY);
    ~planet();

    void update(float time);
    void render();

    void addWater(int lvl);
    void addIron(int lvl);
    void subWater(int lvl);
    void subIron(int lvl);

    sf::Vector2f pos () {return m_pos;/*+m_sprite.GetCenter()*/}

    static float radius() {return 200.f;}

    static std::vector<planet*> g_planets;
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;
    sf::Font m_font;
    int m_type;
    float m_textX;
    float m_textY;

    sf::Vector2f m_pos;
    sf::Vector2f m_cpos;
    int m_waterLvl;
    int m_ironLvl;
};

#endif // PLANET_HPP
