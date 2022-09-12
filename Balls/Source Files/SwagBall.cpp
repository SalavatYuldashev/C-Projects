//
// Created by Salavat on 12.09.2022.
//

#include "../Header Files/SwagBall.h"
//Constructors and Destructors
SwagBall::SwagBall(const sf::RenderWindow& window)
{
    initShape(window);
}
SwagBall::~SwagBall()
{

}

//Private function
void SwagBall::initShape(const sf::RenderWindow& window)
{
    shape.setRadius(static_cast<float>(rand() % 10 + 15));
    sf::Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(
        static_cast<float>(rand()%window.getSize().x - shape.getGlobalBounds().width),
        static_cast<float>(rand()%window.getSize().y - shape.getGlobalBounds().height)));
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
