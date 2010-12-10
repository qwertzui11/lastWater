#include "collector.hpp"

void collector::kill()
{
    if (rand()%10 == 0)
        m_alive = false;
}

