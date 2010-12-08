#include "server.hpp"
#include "stdio.h"
#include <iostream>

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
    else
    {
        std::cout << "Sers bub";
    }

}
