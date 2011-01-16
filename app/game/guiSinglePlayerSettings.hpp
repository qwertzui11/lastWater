#ifndef GUISINGLEPLAYERSETTINGS_HPP
#define GUISINGLEPLAYERSETTINGS_HPP

#include "state.hpp"
#include "gui/button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class guiSinglePlayerSettings : public state, private buttonListener
{
public:
    guiSinglePlayerSettings(sf::RenderWindow *rw);

    bool event(sf::Event *event);
    void update(float time);
    void render();
    void clear();
private:
    static const int g_maxComputer = 7;

    void buttonPressed(button *btn);

    sf::RenderWindow *m_rw;

    std::vector<button*> m_numEnemys;
    button m_exit;

    sf::Font m_font;

    sf::String m_title;
    sf::String m_credits;

};

#endif // GUISINGLEPLAYERSETTINGS_HPP
