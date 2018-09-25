#include "gameAI.h"
#include "gamePlayer.h"
#include <SFML/System.hpp>

gameAI::gameAI()
{
    //ctor
}

void gameAI::movePaddle(gamePlayer* playerWindow, float delta)
{
    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2)
        paddleSpeed = setSpeed/2;
    else if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2)
        paddleSpeed = -setSpeed/2;
    else
        paddleSpeed = 0.f;


    if (((paddleSpeed < 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2 > 5.f)) ||
        ((paddleSpeed > 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2 < gameHeight - 5.f)))
    {
        playerWindow->aiPaddle->Paddle.move(0, paddleSpeed/2 * delta/8);
    }
}
