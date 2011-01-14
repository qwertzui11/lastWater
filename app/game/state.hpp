#ifndef STATE_HPP
#define STATE_HPP

#include "stateListener.hpp"
#include <SFML/Window/Event.hpp>

class state
{
public:
    state();
    ~state();

    void done(state *nextState);
    void setListener (stateListener *st);

    virtual bool event(sf::Event *event) = 0;
    virtual void update(float time) = 0;
    virtual void render() = 0;
    void clear() {;}
private:
    stateListener *m_listener;
};

#endif // STATE_HPP
