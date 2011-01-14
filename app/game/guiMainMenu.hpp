#ifndef GUIMAINMENU_HPP
#define GUIMAINMENU_HPP

#include "gui/button.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "state.hpp"

class guiMainMenu : public state, private buttonListener
{
public:
    guiMainMenu(sf::RenderWindow *rw);
    ~guiMainMenu();

    bool event(sf::Event *event);
    void update(float time);
    void render();
    void clear();
private:
    void buttonPressed(button *btn);

    sf::RenderWindow *m_rw;

    button m_singleplayer;
    /*button m_tutorial;
    button m_credits;*/
    button m_exit;
};

#endif // GUIMAINMENU_HPP
