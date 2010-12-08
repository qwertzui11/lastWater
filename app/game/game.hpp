#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "client.hpp"
#include "server.hpp"

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
    server m_server;
};

#endif // GAME_HPP
