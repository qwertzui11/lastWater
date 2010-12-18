#include "useful.hpp"

sf::Vector2f normalize(sf::Vector2f vec)
{
    float length = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    if (length != 0)
        return sf::Vector2f(vec.x / length, vec.y / length);
    else
        return vec;
}


sf::Vector2f mousePos(sf::RenderWindow *rw)
{
    float xPos = rw->GetDefaultView().GetRect().Left;
    float yPos = rw->GetDefaultView().GetRect().Top;
    xPos += ((float)rw->GetInput().GetMouseX())*((rw->GetDefaultView().GetHalfSize().x*2.f) / ((float)rw->GetWidth()));
    yPos += ((float)rw->GetInput().GetMouseY())*((rw->GetDefaultView().GetHalfSize().y*2.f) / ((float)rw->GetHeight()));
    return sf::Vector2f(xPos, yPos);
}

float length(sf::Vector2f vec)
{
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

