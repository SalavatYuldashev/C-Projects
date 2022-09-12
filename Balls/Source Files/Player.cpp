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
    movementSpeed = 5.f;
    hpMax = 10;
    points = 0;
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
void Player::update(const sf::RenderTarget* target)
{
    updateInput();
    updateWindowBoundsCollision(const_cast<sf::RenderTarget*>(target));

}
void Player::updateInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.move(-movementSpeed, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move(0.f, -movementSpeed);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0.f, movementSpeed);
    }
}
void Player::updateWindowBoundsCollision(sf::RenderTarget* target)
{
    //left
    if (shape.getGlobalBounds().left <= 0.f)
    {
        shape.setPosition(0.f, shape.getGlobalBounds().top);
    }
        //fight
    else if (shape.getGlobalBounds().left + shape.getGlobalBounds().width >= target->getSize().x)
    {
        shape.setPosition(target->getSize().x - shape.getGlobalBounds().width, shape.getGlobalBounds().top);
    }
    //top
    if (shape.getGlobalBounds().top <= 0.f)
    {
        shape.setPosition(shape.getGlobalBounds().left, 0.f);
    }
        //bottom
    else if (shape.getGlobalBounds().top + shape.getGlobalBounds().height >= target->getSize().y)
    {
        shape.setPosition(shape.getGlobalBounds().left, target->getSize().y - shape.getGlobalBounds().height);
    }

}
const sf::RectangleShape& Player::getShape() const
{
    return shape;
}

