#include <SFML/Graphics.hpp>
#include "gamePlayer.h"
#include "gamePaddle.h"
#include "gameBall.h"
#include <iostream>
#include <string>

gamePlayer::gamePlayer() : playerWindow(sf::VideoMode(800,600,32), "Pong, by Jack Bowden", sf::Style::Close) //width by height
{
    playerPaddle = new gamePaddle(playerLocX, playerLocY, "Green");
    aiPaddle = new gamePaddle(aiLocX, aiLocY, "Yellow");
    theGameBall = new gameBall(ballLocX, ballLocY, ballOriginX, ballOriginY);
    playerScore = 0;
    enemyScore = 0;
}

void gamePlayer::paintScore(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("src/sansation.ttf"))
    {
        // error...
    }

    sf::Text text;
    text.setFont(font);
    text.setString("0");
    switch(playerScore)
    {
        case 1: text.setString("1");
    }
    text.setCharacterSize(24);
    text.setPosition(600,300);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    window.draw(text);
}

void gamePlayer::setScore(int player)
{
    if (player == 1)
    {
        playerScore++;
    } else {
        enemyScore++;
    }
}

void gamePlayer::updateView() //refreshes screen with new content
{
    playerWindow.clear(sf::Color::Black);

    playerPaddle -> updateView(playerWindow);
    aiPaddle -> updateView(playerWindow);
    theGameBall -> updateView(playerWindow);
    paintScore(playerWindow);

    playerWindow.display();
}
