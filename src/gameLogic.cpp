#include "gameLogic.h"
#include "gamePlayer.h"
#include <math.h>
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846264338327


gameLogic::gameLogic()
{
    ballSoundBuffer.loadFromFile("assets/bounce.wav");
    wooshSoundBuffer.loadFromFile("assets/woosh.wav");
    ballSound.setVolume(100);
    wooshSound.setVolume(100);
}

//! Inspired by SFML/examples/pong
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
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            ballSound.setBuffer(ballSoundBuffer);
            ballSound.play();
        }
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
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            ballSound.setBuffer(ballSoundBuffer);
            ballSound.play();
        }
    }
}

//! Inspired by SFML/examples/pong
int gameLogic::checkWallBoundaries(gamePlayer* playerWindow)
{
    if (playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() < 0.f) //if its past enemy goal line
    {
        playerWindow ->setScore(1);
        playerWindow->theGameBall->setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            wooshSound.setBuffer(wooshSoundBuffer);
            wooshSound.play();
        }
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() > 800) //if its past player goal line
    {
        playerWindow ->setScore(2);
        playerWindow->theGameBall->setBallAngle((std::rand() % 360) * 2 * M_PI / 360);
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            wooshSound.setBuffer(wooshSoundBuffer);
            wooshSound.play();
        }
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < 0.f) //if it hits the bottom
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->setBallAngle(playerWindow->theGameBall->getBallAngle() + 0.10 * (std::rand() % 5 + -5));
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, playerWindow->theGameBall->objectBall.getRadius() + 0.1f);
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            ballSound.setBuffer(ballSoundBuffer);
            ballSound.play();
        }
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > gameHeight) //if it hits the top
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->setBallAngle(playerWindow->theGameBall->getBallAngle() + 0.10 * (std::rand() % 5 + -5));
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, gameHeight - playerWindow->theGameBall->objectBall.getRadius() - 0.1f);
        if ((playerWindow->isGameNew() != true) && (playerWindow->isGameOver() != true))
        {
            ballSound.setBuffer(ballSoundBuffer);
            ballSound.play();
        }
    }

    if (playerWindow->getFunnyMode() == true)
    {
        if ((playerWindow->aiPaddle->Paddle.getPosition().x < 0) || (playerWindow->aiPaddle->Paddle.getPosition().x > 800)) //if its past player goal line
        {
            playerWindow->aiPaddle->Paddle.setPosition(75, playerWindow->theGameBall->objectBall.getPosition().y);
        }
        if (playerWindow->aiPaddle->Paddle.getPosition().x > playerWindow->theGameBall->objectBall.getPosition().x + 1)
        {
            playerWindow->aiPaddle->Paddle.setPosition(playerWindow->theGameBall->objectBall.getPosition().x - 10, playerWindow->theGameBall->objectBall.getPosition().y);
        }
    }
}
