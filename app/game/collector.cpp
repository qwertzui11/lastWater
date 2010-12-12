#include "collector.hpp"

void collector::kill()
{
    if (rand()%20 == 0)
        m_alive = false;
}

