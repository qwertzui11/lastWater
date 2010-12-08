#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <SFML/System.hpp>

sf::Vector2f normalize(sf::Vector2f vec)
{
    float length = sqrt((vec.x * vec.x) + (vec.y * vec.y));
    if (length != 0)
        return sf::Vector2f(vec.x / length, vec.y / length);
    else
        return vec;
}


#endif // USEFUL_HPP
