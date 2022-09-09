// Created by Salavat on 09.09.2022.
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <ctime>

class Game
{
 private:
    //Variables
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;

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




};


