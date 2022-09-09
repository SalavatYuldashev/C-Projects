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
}
void Game::initVariables()
{
    endGame = false;
}

//Public functions
void Game::render()
{

}
void Game::update()
{

}
