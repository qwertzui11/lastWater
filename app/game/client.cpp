#include "client.hpp"

client::client(sf::RenderWindow *rw)
    : m_rw(rw)
{
}

client::~client()
{
}

void client::initialise()
{
    sf::IPAddress ip("192.168.1.34");
    /*if (m_client.Connect(30000, ip) != sf::Socket::Done)
    {
        return;
    }*/

    if (!m_font.LoadFromFile("cheeseburger.ttf", 500))
    {
        return;
    }

    // sf::String Text("Hello", MyFont, 50);

    // Or, if you want to do it after the construction :

    m_text.SetText("Hello dsfdsssssf sdf sdf dsf s434wwt  sdfs fsd fsd \nfsdfsdfsdfsdf");
    m_text.SetFont(m_font);
    m_text.SetSize(500);

    m_text.SetColor(sf::Color(0, 256, 0));
    /*m_text.SetRotation(90.f);
    m_text.SetScale(2.f, 2.f);
    m_text.Move(100.f, 200.f);*/

}


void client::render()
{
    m_rw->Draw(m_text);
}
