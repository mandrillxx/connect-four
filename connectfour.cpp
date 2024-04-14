#include <iostream>
#include <vector>
#include "game.h"

using namespace std;

int main()
{
    Game game;

    if (RUN_TESTS)
    {
        game.runTests();
        return 0;
    }

    game.playGame();
}
