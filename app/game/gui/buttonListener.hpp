#ifndef BUTTONLISTENER_HPP
#define BUTTONLISTENER_HPP

class button;

class buttonListener
{
public:
    buttonListener();

    virtual void buttonPressed(button *btn) = 0;
};

#endif // BUTTONLISTENER_HPP
