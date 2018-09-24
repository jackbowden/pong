#include "gameLogic.h"
#include "gamePlayer.h"
#include <cmath>
#include <math.h>

gameLogic::gameLogic()
{
    //ctor
}


void gameLogic::checkPaddleBoundaries(gamePlayer* playerWindow)
{
    //fuck
}

int gameLogic::checkWallBoundaries(gamePlayer* playerWindow)
{
    int gameHeight = 800;
    int gameWidth = 600;
    printf("HEY");
    // Check collisions between the ball and the screen
    // gamePlayer->theGameBall->objectBall.getPosition().x - gamePlayer->theGameBall.objectBall.getRadius() < 0.f
    if (playerWindow->theGameBall->objectBall.getPosition().x - playerWindow->theGameBall->objectBall.getRadius() < 0.f)
    {
        printf("hey1");

    }
    if (playerWindow->theGameBall->objectBall.getPosition().x + playerWindow->theGameBall->objectBall.getRadius() > 550) //800 = game width
    {
        printf("HEY2");
    }

    //! YES THIS WORKS
    if (playerWindow->theGameBall->objectBall.getPosition().y - playerWindow->theGameBall->objectBall.getRadius() < 0.f)
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, playerWindow->theGameBall->objectBall.getRadius() + 0.1f);
    }
    if (playerWindow->theGameBall->objectBall.getPosition().y + playerWindow->theGameBall->objectBall.getRadius() > gameHeight)
    {
        playerWindow->theGameBall->invertBallAngle();
        playerWindow->theGameBall->objectBall.setPosition(playerWindow->theGameBall->objectBall.getPosition().x, playerWindow->theGameBall->objectBall.getRadius() - 0.1f);
    }
}
