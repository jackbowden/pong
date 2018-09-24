#include <SFML/Graphics.hpp>

/*
#include "menuStart.h"
#include "gameLogic.h"
*/
#include "gamePlayer.h"
/*
#include "gameAI.h"
#include "gameBall.h"
*/
#include "gamePaddle.h"
/*
#include "menuFinish.h"
*/

#include <iostream>
//! DO I NEED DESTRUCTORS AND IF SO, WHERE?

int main(int argc, char** argv)
{

    gamePlayer* playerWindow = new gamePlayer();

    // process events
    sf::Event Event;

    //add ai and logic here

    playerWindow -> playerWindow.display();

    while(playerWindow -> playerWindow.isOpen())
    {
        while(playerWindow -> playerWindow.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                playerWindow -> playerWindow.close();
                return 0;
            }

        }
        playerWindow -> playerWindow.setFramerateLimit(60);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerWindow -> playerPaddle -> movePaddleUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerWindow -> playerPaddle -> movePaddleDown();
        }

        playerWindow -> updateView();
    }

  // Done.
  return 0;
}
