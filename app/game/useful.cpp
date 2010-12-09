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
    return sf::Vector2f(rw->GetInput().GetMouseX()+rw->GetView().GetCenter().x-rw->GetView().GetHalfSize().x,
                        rw->GetInput().GetMouseY()+rw->GetView().GetCenter().y-rw->GetView().GetHalfSize().y);
}

