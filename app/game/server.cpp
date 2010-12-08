#include "server.hpp"

server::server()
{
}

server::~server()
{

}

void server::initialise()
{
    sf::SocketTCP Listener;
    if (!Listener.Listen(30000))
    {
        // Error...
    }

    sf::IPAddress ClientAddress;
    sf::SocketTCP Client;
    if (Listener.Accept(Client, &ClientAddress) != sf::Socket::Done)
    {
        // Error...
    }

}
