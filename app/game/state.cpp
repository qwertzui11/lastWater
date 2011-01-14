#include "state.hpp"

state::state()
    : m_listener(0)
{
}

state::~state()
{
    clear();
}

void state::setListener (stateListener *st)
{
    m_listener = st;
}

void state::done(state *nextState)
{
    m_listener->done(this, nextState);
}

