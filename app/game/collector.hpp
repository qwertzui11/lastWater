#ifndef COLLECTOR_HPP
#define COLLECTOR_HPP

#include "ship.hpp"
#include "asteroid.hpp"
#include "bubble.hpp"
#include "planet.hpp"

class collector : public ship
{
public:
    collector(sf::Vector2f pos, sf::Image *img, sf::Image *imgBubble, sf::RenderWindow *rw, sf::Color col, planet *home);
    ~collector();
    void kill();
    void update (float timeLastFrame);

    void goTo(sf::Vector2f goTo);
    void getWater(planet *pl);

    enum state
    {
        lookingForAsteroid,
        lookingForWater,
        lookingForPlanet,
        gettingHome,
        manualPositionGoTo
    };
    void setState(state set);
private:


    asteroid* findNearest();
    bubble* findNearestBubble();

    sf::Image *m_imgBubble;

    planet *m_goToPl;
    asteroid *m_goToAs;
    bubble *m_goToBu;
    planet *m_home;

    state m_state;
};

#endif // COLLECTOR_HPP
