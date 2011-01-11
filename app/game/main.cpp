#include "game.hpp"


int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    game gm;
    gm.initialise();

    return gm.run();

}
