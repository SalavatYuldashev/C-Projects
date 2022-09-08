#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Source Files/Game.h"

int main()
{
    std::srand(static_cast<unsigned>(time(NULL)));
    //Window
    Game* game = new Game();

    //Game loop
    while (game ->isRunning())
    {
        game->update();
        game->render();
    }

    return 0;
}