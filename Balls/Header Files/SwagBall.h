// Created by Salavat on 12.09.2022.
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class SwagBall
{
 private:
sf::CircleShape shape;

//function
void initShape(const sf::RenderWindow& window);

 public:
    SwagBall(const sf::RenderWindow& window);
    virtual ~SwagBall();

    //Function
    void update();
    void render(sf::RenderTarget& target);
    const sf::CircleShape getShape() const;

};

