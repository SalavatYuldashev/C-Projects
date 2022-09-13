// Created by Salavat on 09.09.2022.
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Player
{
 private:
    //Variables
    sf::RectangleShape shape;
    float movementSpeed;
    int hp;
    int hpMax;

    //Private function
    void initVariables();
    void initShape();

 public:
    //Constructors and Destructors
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    //Public function
    void render(sf::RenderTarget* target);
    void update(const sf::RenderTarget* target);
    void updateWindowBoundsCollision(sf::RenderTarget* target);
    void updateInput();
    const sf::RectangleShape& getShape() const;
};

