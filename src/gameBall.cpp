#include "gameBall.h"
#include <cmath>
#include <math.h>

gameBall::gameBall(float posX, float posY, float originX, float originY)
{
    objectBall.setRadius(ballRadius);
    //objectBall.setOutlineThickness(3);
    //objectBall.setOutlineColor(sf::Color::Black);
    objectBall.setOrigin(originX, originY);
    objectBall.setPosition(posX, posY);
    //objectBall.setPointCount(50);
    objectBall.setFillColor(sf::Color::White);
}

void gameBall::updateView(sf::RenderWindow& window)
{
    window.draw(objectBall);
}

void gameBall::invertBallAngle()
{
    ballAngle = -ballAngle;
}

void gameBall::moveBall(float delta)
{
    /*
    do
    {
        // Make sure the ball initial angle is not too much vertical
        ballAngle = (std::rand() % 360) * 2 * M_PI / 360;
    }
    while (std::abs(std::cos(ballAngle)) < 0.7f);
    */

    objectBall.move(delta * ballSpeed * std::cos(ballAngle), delta * ballSpeed * std::sin(ballAngle));
    //checkPaddleBoundaries();
}

/*
void gameBall::checkPaddleBoundaries()
{
    if (objectBall.getPosition().x + objectBallRadius > rightPaddle.getPosition().x - paddleSize.x / 2 &&
    objectBall.getPosition().x + objectBallRadius < rightPaddle.getPosition().x &&
    objectBall.getPosition().y + objectBallRadius >= rightPaddle.getPosition().y - paddleSize.y / 2 &&
    objectBall.getPosition().y - objectBallRadius <= rightPaddle.getPosition().y + paddleSize.y / 2)
    {
        if (objectBall.getPosition().y > rightPaddle.getPosition().y)
            ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
        else
            ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;

        ballSound.play();
        ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);
    }
}
*/
