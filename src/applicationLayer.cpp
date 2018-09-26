#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//#include "menuStart.h"
#include "gameLogic.h"
#include "gamePlayer.h"
#include "gameAI.h"
#include "gameBall.h"
#include "gamePaddle.h"
//#include "menuFinish.h"

#include <cmath>
#include <math.h>

#include <iostream>
//! DO I NEED DESTRUCTORS AND IF SO, WHERE?

int main(int argc, char** argv)
{
    gameAI* aiOperation = new gameAI();
    gameLogic* gameOperation = new gameLogic();
    gamePlayer* playerWindow = new gamePlayer();

    playerWindow -> playerWindow.display();

    while(playerWindow -> playerWindow.isOpen())
    {
        sf::Event Event;
        while(playerWindow -> playerWindow.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                playerWindow -> playerWindow.close();
                return 0;
            }

        }
        sf::Clock clock;
        float delta = clock.getElapsedTime().asSeconds() * 100000;
        clock.restart();

        playerWindow -> theGameBall -> moveBall(delta);
        gameOperation -> checkWallBoundaries(playerWindow);
        gameOperation -> checkPaddleBoundaries(playerWindow);

        aiOperation -> movePaddle(playerWindow, delta);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerWindow -> playerPaddle -> movePaddleUp(delta);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerWindow -> playerPaddle -> movePaddleDown(delta);
        }

        playerWindow -> updateView();
    };

  // Done.
  return 0;
}
