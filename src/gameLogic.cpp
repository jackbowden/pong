#include "gameLogic.h"
#include "gamePlayer.h"
#include <cmath>
#include <math.h>

gameLogic::gameLogic()
{

}


void gameLogic::checkPaddleBoundaries(gamePlayer* playerWindow)
{
    //fuck
}

int gameLogic::checkWallBoundaries(gamePlayer* playerWindow)
{
    int gameHeight = 600;
    int gameWidth = 800;
    if (playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() < 0.f)
    {
        playerScore += 1;
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() > 800) //800 = game width
    {
        enemyScore += 1;
        playerWindow ->theGameBall->resetBall();
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < 0.f)
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, playerWindow->theGameBall->objectBall.getRadius() + 0.1f);
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > gameHeight)
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, gameHeight - playerWindow->theGameBall->objectBall.getRadius() - 0.1f);
    }
}
