#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "client.hpp"

class game
{
public:
    game();
    ~game();

    /* startup */
    void initialise();

    int run();
private:

    sf::RenderWindow m_window;
    client m_client;

};

#endif // GAME_HPP
