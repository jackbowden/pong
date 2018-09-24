#include "gameLogic.h"
#include "gamePlayer.h"
#include <cmath>
#include <math.h>

gameLogic::gameLogic()
{
    //ctor
}

void gameLogic::moveBall(gamePlayer* playerWindow, float delta)
{

    float ballAngle = 90.f;
    /*
    do
    {
        // Make sure the ball initial angle is not too much vertical
        ballAngle = (std::rand() % 360) * 2 * M_PI / 360;
    }
    while (std::abs(std::cos(ballAngle)) < 0.7f);
    */
    float ballSpeed = 900000.f;
    //float factor = ballSpeed * delta;
    //playerWindow->theGameBall->objectBall.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);


    //sf::Clock clock;
    //float deltaa = clock.getElapsedTime().asSeconds();
    playerWindow->theGameBall->objectBall.move(delta * ballSpeed * std::cos(ballAngle), delta * ballSpeed * std::sin(ballAngle));
}
