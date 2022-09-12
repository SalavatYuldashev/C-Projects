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
    window->setFramerateLimit(60);
}
void Game::initVariables()
{
    endGame = false;
    spawnTimerMax = 10.f;
    spawnTimer = spawnTimerMax;
    maxSwagBalls = 2000;

}

//Public functions
void Game::render()
{
    window->clear();

    //Render stuff
    player->Player::render(window);
    for (auto i : swagBalls)
    {
        i.render(*window);
    }

    window->display();
}
void Game::update()
{
    pollEvents();
    spawnSwagBalls();
    player->update(window);
    updateCollision();
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
void Game::spawnSwagBalls()
{
    //Timer
    if (spawnTimerMax < spawnTimer)
    {
        spawnTimer += 0.1f;
    }
    else
    {
        if (swagBalls.size() < maxSwagBalls)
        {
            swagBalls.push_back(SwagBall(*this->window));
            spawnTimer = 0.f;
        }

    }
}
void Game::updateCollision()
{
    for (size_t i = 0; i < swagBalls.size(); i++)
    {
        if (player->getShape().getGlobalBounds().
            intersects(swagBalls[i].getShape().getGlobalBounds()))
        {
            swagBalls.erase(swagBalls.begin()+i);
        }
    }

}
