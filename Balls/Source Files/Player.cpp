// Created by Salavat on 09.09.2022.

#include "../Header Files/Player.h"

//Constructors and Destructors
Player::Player(float x, float y)
{
    shape.setPosition(x, y);
    initVariables();
    initShape();
}
Player::~Player()
{

}

//Private functions
void Player::initVariables()
{
    movementSpeed = 10.f;
}
void Player::initShape()
{
    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(50.f, 50.f));
}

//Public function
void Player::render(sf::RenderTarget* target)
{
    target->draw(shape);

}
void Player::update()
{
   updateInput();
}
void Player::updateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.move(-movementSpeed , 0.f );
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(movementSpeed, 0.f );
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move( 0.f,-movementSpeed );
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move( 0.f,movementSpeed );
    }
}

