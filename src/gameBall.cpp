#include "gameBall.h"
#include <cmath>
#include <math.h>
#define M_PI 3.14159265358979323846264338327

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

void gameBall::resetBall()
{
    setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
    objectBall.setPosition(originX, originY);
}

void gameBall::invertBallAngle()
{
    ballAngle = -ballAngle;
}

float gameBall::getBallAngle()
{
    return ballAngle;
}

float gameBall::setBallAngle(float newBallAngle)
{
    ballAngle = newBallAngle;
}

void gameBall::moveBall(float delta)
{
    float ballSpeedOverGameTime = delta * ballSpeed;
    objectBall.move(ballSpeedOverGameTime * std::cos(ballAngle), ballSpeedOverGameTime * std::sin(ballAngle));
}

void gameBall::spawnBall()
{
    do
    {
        // Make sure the ball initial angle is not too much vertical
        setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
    }
    while (std::abs(std::cos(ballAngle)) < 0.7f);
}
