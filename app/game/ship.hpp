#ifndef SHIP_HPP
#define SHIP_HPP

#include "SFML/Graphics.hpp"

class ship
{
public:
    ship(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col);
    ~ship();

    void update(float timeLastFrame);
    void render();
    sf::Vector2f pos();
    void setSelected(bool sel);
    bool isSelected();

    void goTo(sf::Vector2f goTo);

    sf::FloatRect collRect();

    static std::vector<ship*> g_ships;
    static const float g_radius = 15.f;

    virtual void kill() = 0;
    bool alive() {return m_alive;}
protected:
    bool m_alive;
private:
    sf::RenderWindow *m_rw;
    sf::Sprite m_sprite;

    sf::Vector2f m_goTo;

    sf::Shape *m_selected;
};

#endif // SHIP_HPP
