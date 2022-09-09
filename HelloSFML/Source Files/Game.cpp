//
// Created by Salavat on 07.09.2022.
//
#include "Game.h"

//constructors and destructors
Game::Game()
{
    Game::initVariables();
    Game::initWindow();
    Game::initEnemies();
}

Game::~Game()
{
    delete Game::window;
}

//private functions
void Game::initVariables()
{
    Game::window = nullptr;

    //Game logic
    Game::points = 0;
    Game::enemySpawnTimerMax = 10.f;
    Game::enemySpawnTimer = Game::enemySpawnTimerMax;
    Game::maxEnemies = 1000;
    Game::moveSpeed = 0.8f;
    Game::mouseHeld = false;
}

void Game::initWindow()
{
    Game::videoMode.height = 600;
    Game::videoMode.width = 800;
    Game::window = new sf::RenderWindow(Game::videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);
    Game::window->setFramerateLimit(144);
}

void Game::initEnemies()
{
    Game::enemy.setPosition(300.f, 400.f);
    Game::enemy.setSize(sf::Vector2f(100.f, 100.f));
    Game::enemy.setScale(0.5f, 0.5f);
    Game::enemy.setFillColor(sf::Color::Green);
    Game::enemy.setOutlineColor(sf::Color::Green);
    Game::enemy.setOutlineThickness(5.f);
}
//Accessors

const bool Game::isRunning() const
{
    return Game::window->isOpen();
}

//public functions
void Game::update()
{
    pollEvents();
    updateMousePosition();
    Game::updateEnemy();
    //Game::enemy.setPosition(Game::mousePositionWindow.x,Game::mousePositionWindow.y);
}

void Game::render()
{
    Game::window->clear();

    //Draw game objects
    //Game::window->draw(Game::enemy);
    Game::renderEnemy();

    Game::window->display();
}

void Game::pollEvents()
{
    while (Game::window->pollEvent(Game::event))
    {
        switch (Game::event.type)
        {
        case sf::Event::Closed:
            Game::window->close();
            break;
        case sf::Event::KeyPressed:
            if (Game::event.key.code == sf::Keyboard::Escape)
            {
                Game::window->close();
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                std::cout << "mouseLeftPressed" << std::endl;
            }
            break;
        case sf::Event::Resized:
            std::cout << "new width: " << event.size.width << std::endl;
            std::cout << "new height: " << event.size.height << std::endl;
            break;
        }

    }
}
void Game::updateMousePosition()
{
    Game::mousePositionWindow = sf::Mouse::getPosition(*Game::window);
    Game::mousePosView = Game::window->mapPixelToCoords(Game::mousePositionWindow);
}

void Game::spawnEnemy()
{
    Game::enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(Game::window->getSize().x - Game::enemy.getSize().x / 2)),
        static_cast<float>(rand() % static_cast<int>((Game::window->getSize().y / 2) - Game::enemy.getSize().y)));
    Game::enemy.setFillColor(sf::Color::Green);
    Game::enemies.push_back(Game::enemy);

}
void Game::updateEnemy()
{
    bool deleted = false;
    if (Game::enemies.size() < Game::maxEnemies)
    {
        if (Game::enemySpawnTimer >= Game::enemySpawnTimerMax)
        {
            Game::spawnEnemy();
            Game::enemySpawnTimer = 0.f;
        }
        else
        {
            Game::enemySpawnTimer += 1.0f;
        }
    }
    for (int i = 0; i < Game::enemies.size(); i++)
    {
        Game::enemies[i].move(0.f, moveSpeed);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (Game::enemies[i].getGlobalBounds().contains(Game::mousePosView))
            {
                deleted = true;

                //Gain points
                Game::points += 10.f;
                std::cout << Game::points << std::endl;
            }
        }
        //std::cout << Game::enemies[i].getPosition().y << std::endl;
        //std::cout << Game::window->getSize().y<< std::endl;
        if (Game::enemies[i].getPosition().y > Game::window->getSize().y)
        {
            Game::enemies.erase(Game::enemies.begin() + i);
        }
        if (deleted)
        {
            Game::enemies.erase(Game::enemies.begin() + i);
            deleted = false;
        }
    }
}
void Game::renderEnemy()
{
    for (auto& currentEnemy : Game::enemies)
    {
        Game::window->draw(currentEnemy);
    }
}
void Game::killEnemy()
{

}





