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

    sf::Text displayPlayerScore;
    displayPlayerScore.setFont(font);
    displayPlayerScore.setString("0");
    switch(playerScore)
    {
        case 1: displayPlayerScore.setString("1");
        break;
        case 2: displayPlayerScore.setString("2");
        break;
        case 3: displayPlayerScore.setString("3");
        break;
        case 4: displayPlayerScore.setString("4");
        break;
        case 5: displayPlayerScore.setString("5");
        break;
        case 6: displayPlayerScore.setString("6");
        break;
        case 7: displayPlayerScore.setString("7");
        break;
        case 8: displayPlayerScore.setString("8");
        break;
        case 9: displayPlayerScore.setString("9");
        break;
        case 10: displayPlayerScore.setString("10");
        break;
        case 11: displayPlayerScore.setString("11");
        break;
    }
    displayPlayerScore.setCharacterSize(24);
    displayPlayerScore.setPosition(600,300);
    displayPlayerScore.setFillColor(sf::Color::Green);
    displayPlayerScore.setStyle(sf::Text::Bold);

    window.draw(displayPlayerScore);

    sf::Text displayEnemyScore;
    displayEnemyScore.setFont(font);
    displayEnemyScore.setString("0");
    switch(enemyScore)
    {
        case 1: displayPlayerScore.setString("1");
        break;
        case 2: displayPlayerScore.setString("2");
        break;
        case 3: displayPlayerScore.setString("3");
        break;
        case 4: displayPlayerScore.setString("4");
        break;
        case 5: displayPlayerScore.setString("5");
        break;
        case 6: displayPlayerScore.setString("6");
        break;
        case 7: displayPlayerScore.setString("7");
        break;
        case 8: displayPlayerScore.setString("8");
        break;
        case 9: displayPlayerScore.setString("9");
        break;
        case 10: displayPlayerScore.setString("10");
        break;
        case 11: displayPlayerScore.setString("11");
        break;
    }
    displayEnemyScore.setCharacterSize(24);
    displayEnemyScore.setPosition(200,300);
    displayEnemyScore.setFillColor(sf::Color::Yellow);
    displayEnemyScore.setStyle(sf::Text::Bold);

    window.draw(displayEnemyScore);
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
