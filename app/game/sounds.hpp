#ifndef SOUNDS_HPP
#define SOUNDS_HPP

#include <SFML/Audio/SoundBuffer.hpp>

class sounds
{
public:
    static sf::SoundBuffer *g_button;
    static sf::SoundBuffer *g_shot;
    static sf::SoundBuffer *g_explosion;
    static sf::SoundBuffer *g_win;
    static sf::SoundBuffer *g_loose;
};

#endif // SOUNDS_HPP
