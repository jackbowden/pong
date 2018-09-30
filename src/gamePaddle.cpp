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
    else
    {
        Paddle.setFillColor(sf::Color::White);
    }
}

void gamePaddle::updateView(sf::RenderWindow& window)
{
    window.draw(Paddle);
}

void gamePaddle::movePaddleUp(float delta)
{
    if (Paddle.getPosition().y > 50)
    {
        Paddle.move(0, delta * -250);
    }
}

void gamePaddle::movePaddleDown(float delta)
{
    if (Paddle.getPosition().y < 550)
    {
        Paddle.move(0,delta * 250);
    }
}
