#include "gameAI.h"
#include "gamePlayer.h"
#include <SFML/System.hpp>

gameAI::gameAI()
{
    //ctor
}

void gameAI::movePaddle(gamePlayer* playerWindow, float delta)
{
    /*
    sf::Clock AITimer;
    const sf::Time AITime = sf::seconds(0.1f);
    if (AITimer.getElapsedTime() > AITime)
    {
        AITimer.restart();*/
        if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2)
            paddleSpeed = setSpeed;
        else if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2)
            paddleSpeed = -setSpeed;
        else
            paddleSpeed = 0.f;

        printf("%.6f", paddleSpeed);
    //}


    if (((paddleSpeed < 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2 > 5.f)) ||
        ((paddleSpeed > 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2 < gameHeight - 5.f)))
    {
        playerWindow->aiPaddle->Paddle.move(0.f, paddleSpeed * delta);
    }
}
