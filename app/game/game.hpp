#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "ship.hpp"

class game
{
public:
    game();
    ~game();

    /* startup */
    void initialise();

    int run();

    void update(float timeLastFrame);
    void render();
private:

    sf::RenderWindow m_window;
    sf::Image m_imgShip;
    ship *m_test;
};

#endif // GAME_HPP
