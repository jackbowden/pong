#include <SFML/Graphics.hpp>

/*
#include "menuStart.h"
#include "gameLogic.h"
*/
#include "gamePlayer.h"
/*
#include "gameAI.h"
#include "gameBall.h"
#include "gamePaddle.h"
#include "menuFinish.h"
*/

#include <iostream>
//! DO I NEED DESTRUCTORS AND IF SO, WHERE?

int main(int argc, char** argv)
{


    /* how to handle the fuckin game

    spawn the player, ai, logic, ball, and paddles

    */

    gamePlayer* playerWindow = new gamePlayer();

    // process events
    sf::Event Event;

    playerWindow -> playerWindow.display();
    playerWindow -> updateView();

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
        playerWindow -> updateView();
    }

  // Done.
  return 0;
}