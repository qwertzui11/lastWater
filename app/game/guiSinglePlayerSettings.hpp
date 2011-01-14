#ifndef GUISINGLEPLAYERSETTINGS_HPP
#define GUISINGLEPLAYERSETTINGS_HPP

#include "state.hpp"
#include "gui/button.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class guiSinglePlayerSettings : public state
{
public:
    guiSinglePlayerSettings();
private:
    static const int g_maxComputer = 15;
};

#endif // GUISINGLEPLAYERSETTINGS_HPP
