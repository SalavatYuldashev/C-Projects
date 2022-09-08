// Created by Salavat on 07.09.2022.

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <ctime>

class Game
{
 private:
    //Variables

    //Window
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    //Mouse positions
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePosView;

    //Game logic
    unsigned int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    float moveSpeed;
    bool mouseHeld;

    //Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

 public:
    //Constructors / Destructors
    Game();

    virtual ~Game();

    //Accessors
    const bool isRunning() const;
    //Public Functions
    void spawnEnemy();
    void updateEnemy();
    void renderEnemy();
    void pollEvents();
    void updateMousePosition();
    void update();
    void render();
    void killEnemy();
};



