// Created by Salavat on 09.09.2022.
#include "../Header Files/Game.h"

//Constructors and Destructors
Game::Game()
{
    initVariables();
    initWindow();
}

Game::~Game()
{
    delete Game::window;
}

//Private functions
void Game::initWindow()
{
    videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Balls", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(144);
}
void Game::initVariables()
{
    endGame = false;
}

//Public functions
void Game::render()
{
    window->clear();

    //Render stuff
    player->Player::render(window);

    window->display();
}
void Game::update()
{
    pollEvents();
    player->update();
}
bool Game::running() const
{
    return window->isOpen();
}
void Game::pollEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
            {
                window->close();
            }
            break;
        }
    }
}
