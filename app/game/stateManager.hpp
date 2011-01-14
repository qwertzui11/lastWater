#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include "stateListener.hpp"
#include "state.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class stateManager : private stateListener
{
public:
    stateManager(state *start, sf::RenderWindow *rw);
    ~stateManager();

    void done (state *from, state *next);

    int run();
private:
    sf::RenderWindow *m_rw;

    state *m_current;
};

#endif // STATEMANAGER_HPP
