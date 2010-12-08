#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Graphics.hpp>
#include "SFML/Network/SocketTCP.hpp"
#include "SFML/Network/IPAddress.hpp"

class client
{
public:
    client(sf::RenderWindow *rw);
    ~client();

    void initialise();

    void render();
private:
    sf::SocketTCP m_client;
    sf::RenderWindow *m_rw;

    sf::String m_text;
    sf::Font m_font;
};

#endif // CLIENT_HPP
