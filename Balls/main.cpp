#include "Header Files/Game.h"

int main()
{
    //initialize random seed
    srand(static_cast<unsigned>(time(0)));

    //Initialize Game object
    Game* game = new Game;

    //Game loop
    while (game->running())
    {
        game->render();
        game->update();

    }

    return 0;
}
