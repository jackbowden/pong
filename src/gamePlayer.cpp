#include <SFML/Graphics.hpp>
#include "gamePlayer.h"
#include "gamePaddle.h"

gamePlayer::gamePlayer() : playerWindow(sf::VideoMode(800,600,32), "Pong, by Jack Bowden", sf::Style::Close) //width by height
{


    playerPaddle = new gamePaddle(playerLocX, playerLocY, "Green");
    aiPaddle = new gamePaddle(aiLocX, aiLocY, "Yellow");
    //gameBall = new gameBall(ballLocX, ballOriginX, ballOriginY);
}

void gamePlayer::updateView() //refreshes screen with new content
{
    playerWindow.clear(sf::Color::Black);
    playerPaddle -> updateView(playerWindow);
    aiPaddle -> updateView(playerWindow);
    playerWindow.display();
}
