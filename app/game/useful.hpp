#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>


sf::Vector2f normalize(sf::Vector2f vec);
sf::Vector2f mousePos(sf::RenderWindow *rw);
float length(sf::Vector2f vec);

#endif // USEFUL_HPP
