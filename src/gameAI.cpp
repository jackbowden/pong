#include "gameAI.h"
#include "gamePlayer.h"

gameAI::gameAI()
{
    //ctor
}

void gameAI::movePaddle(gamePlayer* playerWindow, float delta)
{

    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2)
        paddleSpeed = setSpeed;
    else if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2)
        paddleSpeed = -setSpeed;
    else
        paddleSpeed = 0.f;


    if (((paddleSpeed < 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2 > 5.f)) ||
        ((paddleSpeed > 0.f) && (playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2 < gameHeight - 5.f)))
    {
        if (playerWindow->getFunnyMode() == true)
        {
            playerWindow->aiPaddle->Paddle.move(abs(paddleSpeed/32), paddleSpeed * delta/8);
        } else {
            playerWindow->aiPaddle->Paddle.move(0, paddleSpeed * delta/8);
        }
    }
}
