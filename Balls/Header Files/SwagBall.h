// Created by Salavat on 12.09.2022.
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

enum SwagBallTypes
{
    DEFAULT = 0, DAMAGING, HEALING, COUNTTYPES
};

class SwagBall
{
 private:
    sf::CircleShape shape;
    int type;

//function
    void initShape(const sf::RenderWindow& window);

 public:
    SwagBall(const sf::RenderWindow& window, int type);
    virtual ~SwagBall();

    //Accessor
    const int& getType() const;

    //Function
    void update();
    void render(sf::RenderTarget& target);
    const sf::CircleShape getShape() const;

};

