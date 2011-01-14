#ifndef STATE_HPP
#define STATE_HPP

#include "stateListener.hpp"
#include <SFML/Window/Event.hpp>

class state
{
public:
    state()
        : m_listener(0)
    {
    }
    ~state()
    {
        clear();
    }
    void setListener (stateListener *st)
    {
        m_listener = st;
    }
    void done(state *nextState)
    {
        m_listener->done(this, nextState);
    }


    virtual bool event(sf::Event *event) = 0;
    virtual void update(float time) = 0;
    virtual void render() = 0;
    void clear() {;}
private:
    stateListener *m_listener;
};

#endif // STATE_HPP
