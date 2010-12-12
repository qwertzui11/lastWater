#ifndef USEFUL_HPP
#define USEFUL_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include <vector>


sf::Vector2f normalize(sf::Vector2f vec);
sf::Vector2f mousePos(sf::RenderWindow *rw);
float length(sf::Vector2f vec);

template <class T>
T* findByPos(std::vector<T*> vec, sf::Vector2f pos)
{
    typedef typename std::vector<T*>::iterator t_it;
    for (t_it it = vec.begin(); it < vec.end(); ++it)
    {
        if (length((*it)->pos() - pos) < T::size())
            return (*it);
    }
    return 0;
}

/*template <class T>
T* findNearest(std::vector<T*> vec, sf::Vector2f pos)
{
    typedef typename std::vector<T*>::iterator t_it;

    T* nearest = 0;
    for (t_it it = vec.begin(); it < vec.end(); ++it)
    {
        if (length((*it)->pos() - pos) < T::size())
            return (*it);
    }
    return 0;
}*/

template <class T>
bool findAndDelete(std::vector<T*> *vec, T* toFind)
{
    typedef typename std::vector<T*>::iterator t_it;
    for (t_it it = vec->begin(); it < vec->end(); ++it)
    {
        if ((*it) == toFind)
        {
            vec->erase(it);
            return true;
        }
    }
    return false;
}

template <class T>
T* find(std::vector<T*> vec, T* toFind)
{
    typedef typename std::vector<T*>::iterator t_it;
    for (t_it it = vec.begin(); it < vec.end(); ++it)
    {
        if ((*it) == toFind)
        {
            return (*it);

        }
    }
    return 0;
}


#endif // USEFUL_HPP
