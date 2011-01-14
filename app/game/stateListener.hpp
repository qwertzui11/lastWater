#ifndef STATELISTENER_HPP
#define STATELISTENER_HPP

class state;

class stateListener
{
public:
//    stateListener();
    virtual void done (state *from, state *next) = 0;
};

#endif // STATELISTENER_HPP
