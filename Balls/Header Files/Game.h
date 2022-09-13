// Created by Salavat on 09.09.2022.
#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Player.h"
#include "SwagBall.h"

class Game
{
 private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event event;
    Player* player = new Player(300., 300.);
    std::vector<SwagBall> swagBalls;
    float spawnTimerMax;
    float spawnTimer;
    int maxSwagBalls;
    int points;
    sf::Font font;
    sf::Text guiText;
    sf::Text endGameText;

    //Private functions
    void initWindow();
    void initVariables();
    void initFont();
    void initText();

 public:
    //Constructors and Destructors
    Game();
    ~Game();
    //Accessors
    const bool& getEndGame() const;
    //Modifiers

    //Functions
    void render();
    void update();
    [[nodiscard]] bool running() const;
    void pollEvents();
    void spawnSwagBalls();
    void updatePlayer();
    void updateCollision();
    void renderGUI(sf::RenderTarget* target);
    void updateGUI();
    const int randBallType();
};


