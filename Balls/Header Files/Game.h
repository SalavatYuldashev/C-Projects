// Created by Salavat on 09.09.2022.
#pragma once

#include <iostream>
#include <ctime>

#include "Player.h"


class Game
{
 private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event event;
    Player* player = new Player(300.,300.);

    //Private functions
    void initWindow();
    void initVariables();

 public:
    //Constructors and Destructors
    Game();
    ~Game();
    //Accessors

    //Modifiers

    //Functions
    void render();
    void update();
    [[nodiscard]] bool running() const;
    void pollEvents();




};


