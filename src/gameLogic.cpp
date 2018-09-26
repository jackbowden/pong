#include "gameLogic.h"
#include "gamePlayer.h"
#include <math.h>
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846264338327


gameLogic::gameLogic()
{
    playerScore = 0;
    enemyScore = 0;
}


void gameLogic::checkPaddleBoundaries(gamePlayer* playerWindow)
{
    if (playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() < playerWindow->aiPaddle->Paddle.getPosition().x + playerWindow->aiPaddle->Paddle.getSize().x / 2 &&
        playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() > playerWindow->aiPaddle->Paddle.getPosition().x &&
        playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() >= playerWindow->aiPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2 &&
        playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() <= playerWindow->aiPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2)
    {
        if (playerWindow->theGameBall->objectBall.getPosition().y > playerWindow->aiPaddle->Paddle.getPosition().y)
            playerWindow->theGameBall->setBallAngle(M_PI - playerWindow->theGameBall->getBallAngle() + (std::rand() % 20) * M_PI / 180);
        else
            playerWindow->theGameBall->setBallAngle(M_PI - playerWindow->theGameBall->getBallAngle() - (std::rand() % 20) * M_PI / 180);

        playerWindow->theGameBall->objectBall.setPosition(playerWindow->aiPaddle->Paddle.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() + playerWindow->aiPaddle->Paddle.getSize().x / 2 + 0.1f, playerWindow->theGameBall->objectBall.getPosition().y);
    }

    if (playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() > playerWindow->playerPaddle->Paddle.getPosition().x - playerWindow->playerPaddle->Paddle.getSize().x / 2 &&
        playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() < playerWindow->playerPaddle->Paddle.getPosition().x &&
        playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() >= playerWindow->playerPaddle->Paddle.getPosition().y - playerWindow->aiPaddle->Paddle.getSize().y / 2 &&
        playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() <= playerWindow->playerPaddle->Paddle.getPosition().y + playerWindow->aiPaddle->Paddle.getSize().y / 2)
    {
        if (playerWindow->theGameBall->objectBall.getPosition().y > playerWindow->playerPaddle->Paddle.getPosition().y)
            playerWindow->theGameBall->setBallAngle(M_PI - playerWindow->theGameBall->getBallAngle() + (std::rand() % 20) * M_PI / 180);
        else
            playerWindow->theGameBall->setBallAngle(M_PI - playerWindow->theGameBall->getBallAngle() - (std::rand() % 20) * M_PI / 180);

        playerWindow->theGameBall->objectBall.setPosition(playerWindow->playerPaddle->Paddle.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() - playerWindow->aiPaddle->Paddle.getSize().x / 2 - 0.1f, playerWindow->theGameBall->objectBall.getPosition().y);
    }
}

int gameLogic::checkWallBoundaries(gamePlayer* playerWindow)
{
    int gameHeight = 600;
    int gameWidth = 800;
    if (playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() < 0.f)
    {
        enemyScore += 1;
        playerWindow->theGameBall->setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() > 800) //800 = game width
    {
        playerScore += 1;
        playerWindow->theGameBall->setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < 0.f) //if it hits the top
    {
        std::cout << playerWindow->theGameBall->getBallAngle() << std::endl;
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->setBallAngle(playerWindow->theGameBall->getBallAngle() + 0.10 * (std::rand() % 5 + -5));
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, playerWindow->theGameBall->objectBall.getRadius() + 0.1f);
        std::cout << playerWindow->theGameBall->getBallAngle() << std::endl;
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > gameHeight) //if it hits the bottom
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->setBallAngle(playerWindow->theGameBall->getBallAngle() + 0.10 * (std::rand() % 5 + -5));
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, gameHeight - playerWindow->theGameBall->objectBall.getRadius() - 0.1f);
    }
}

int gameLogic::getPlayerScore()
{
    return playerScore;
}

int gameLogic::getEnemyScore()
{
    return enemyScore;
}

void gameLogic::updateView()
{
    std::cout << enemyScore << std::endl << playerScore;
}
