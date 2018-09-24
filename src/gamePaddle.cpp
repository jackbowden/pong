#include "gamePaddle.h"
#include <string>

#include <SFML/Graphics.hpp>

gamePaddle::gamePaddle(float x, float y, std::string color)
{
    sf::Vector2f paddleSize(20, 100);
    Paddle.setSize(paddleSize - sf::Vector2f(3, 3));
    Paddle.setOutlineThickness(3);
    Paddle.setOrigin(paddleSize / 2.f);
    Paddle.setPosition(x, y / 2);


    if (color == "Green")
    {
        Paddle.setFillColor(sf::Color::Green);
    }
    else if (color == "Yellow")
    {
        Paddle.setFillColor(sf::Color::Yellow);
    }
}

void gamePaddle::updateView(sf::RenderWindow& window)
{
    window.draw(Paddle);
}

void gamePaddle::movePaddleUp()
{
    if (Paddle.getPosition().y > 50)
    {
        Paddle.move(0,-10);
    }
}

void gamePaddle::movePaddleDown()
{
    if (Paddle.getPosition().y < 550)
    {
        Paddle.move(0,10);
    }
}
