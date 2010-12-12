#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include "ship.hpp"
#include "asteroid.hpp"
#include "planet.hpp"

class collector : public ship
{
public:
    collector(sf::Vector2f pos, sf::Image *img, sf::RenderWindow *rw, sf::Color col, planet *home);
    ~collector();
    void kill();
    void update (float timeLastFrame);

    void goTo(sf::Vector2f goTo);

    enum state
    {
        lookingForAsteroid,
        lookingForWater,
        gettingHome,
        manualPositionGoTo
    };
    void setState(state set);
private:


    asteroid* findNearest();

    planet *m_goToPl;
    asteroid *m_goToAs;
    planet *m_home;

    state m_state;
};

#endif // COLLECTOR_HPP
