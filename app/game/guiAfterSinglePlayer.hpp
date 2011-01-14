#ifndef GUIAFTERSINGLEPLAYER_HPP
#define GUIAFTERSINGLEPLAYER_HPP

#include "state.hpp"
#include "gui/button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

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
private:
    void buttonPressed(button *btn);
    sf::RenderWindow *m_rw;

    staticText m_status;
    button m_restart;
    button m_exit;

    bool m_activ;
};

#endif // GUIAFTERSINGLEPLAYER_HPP
