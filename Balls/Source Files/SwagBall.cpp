//
// Created by Salavat on 12.09.2022.
//

#include "../Header Files/SwagBall.h"
//Constructors and Destructors
SwagBall::SwagBall(const sf::RenderWindow& window, int type)
{
    SwagBall::type = type;
    initShape(window);
}
SwagBall::~SwagBall()
{

}

//Private function
void SwagBall::initShape(const sf::RenderWindow& window)
{
    shape.setRadius(static_cast<float>(rand() % 10 + 15));
    sf::Color color = sf::Color::White;
    switch (type)
    {
    case DEFAULT:
        color = sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
        break;
    case DAMAGING:
        color = sf::Color(sf::Color::Red);
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(4.f);
        break;
    case HEALING:
        color = sf::Color(sf::Color::Green);
        shape.setOutlineColor(sf::Color::White);
        shape.setOutlineThickness(4.f);
        break;
    }

    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(
        static_cast<float>(rand() % window.getSize().x - shape.getGlobalBounds().width),
        static_cast<float>(rand() % window.getSize().y - shape.getGlobalBounds().height)));
}

//Public function
void SwagBall::update()
{

}
void SwagBall::render(sf::RenderTarget& target)
{
    target.draw(shape);

}
const sf::CircleShape SwagBall::getShape() const
{
    return shape;
}
const int& SwagBall::getType() const
{
    return type;
}
