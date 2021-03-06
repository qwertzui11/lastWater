#ifndef GUIAFTERSINGLEPLAYER_HPP
#define GUIAFTERSINGLEPLAYER_HPP

#include "state.hpp"
#include "gui/button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/String.hpp>

class guiAfterSinglePlayer : public state, private buttonListener
{
public:
    guiAfterSinglePlayer(float worldSize, sf::RenderWindow *rw);

    bool event(sf::Event *event);
    void update(float time);
    void render();
    void clear();

    void activate(bool activ);
    bool active() {return m_activ;}    

    enum status
    {
        won,
        lost,
        pause
    };

    void setStatus (status st);
    status getStatus() {return m_statusStatus;}

    bool restart() {return m_bRestart;}
    bool exit() {return m_bExit;}
private:
    void buttonPressed(button *btn);
    sf::RenderWindow *m_rw;

    staticText m_status;
    button m_restart;
    button m_exit;

    bool m_activ;

    status m_statusStatus;

    bool m_bRestart;
    bool m_bExit;
};

#endif // GUIAFTERSINGLEPLAYER_HPP
