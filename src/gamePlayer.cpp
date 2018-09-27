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
    gameState = 0;
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
        case 11: displayPlayerScore.setString("11"); setGameState(2);
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
        case 1: displayEnemyScore.setString("1");
        break;
        case 2: displayEnemyScore.setString("2");
        break;
        case 3: displayEnemyScore.setString("3");
        break;
        case 4: displayEnemyScore.setString("4");
        break;
        case 5: displayEnemyScore.setString("5");
        break;
        case 6: displayEnemyScore.setString("6");
        break;
        case 7: displayEnemyScore.setString("7");
        break;
        case 8: displayEnemyScore.setString("8");
        break;
        case 9: displayEnemyScore.setString("9");
        break;
        case 10: displayEnemyScore.setString("10");
        break;
        case 11: displayEnemyScore.setString("11"); setGameState(2);
        break;
    }
    displayEnemyScore.setCharacterSize(24);
    displayEnemyScore.setPosition(200,300);
    displayEnemyScore.setFillColor(sf::Color::Yellow);
    displayEnemyScore.setStyle(sf::Text::Bold);

    window.draw(displayEnemyScore);
}

void gamePlayer::displayGameOver(sf::RenderWindow& window, int winner)
{
    sf::Font font;
    if (!font.loadFromFile("src/sansation.ttf"))
    {
        // error...
    }

    playerWindow.clear(sf::Color::Black);

    sf::Text gameOverScreenText;
    gameOverScreenText.setFont(font);
    if (winner == 1)
    {
        gameOverScreenText.setString("Game Over!\nThe player won!\nPress up arrow to play again\nPress ESC to exit.");
    } else {
        gameOverScreenText.setString("Game Over!\nThe AI won!\nPress up arrow to play again\nPress ESC to exit.");
    }
    gameOverScreenText.setCharacterSize(24);
    gameOverScreenText.setPosition(400,300);
    gameOverScreenText.setFillColor(sf::Color::White);
    gameOverScreenText.setStyle(sf::Text::Bold);

    window.draw(gameOverScreenText);
    playerWindow.display();

}

void gamePlayer::displayGameNew(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("src/sansation.ttf"))
    {
        // THROW ERROR
    }

    playerWindow.clear(sf::Color::Black);

    sf::Text gameOverScreenText;
    gameOverScreenText.setFont(font);
    gameOverScreenText.setString("Welcome!\nPress up arrow to play\nPress ESC to exit.");
    gameOverScreenText.setCharacterSize(24);
    gameOverScreenText.setPosition(400,300);
    gameOverScreenText.setFillColor(sf::Color::White);
    gameOverScreenText.setStyle(sf::Text::Bold);

    window.draw(gameOverScreenText);
    playerWindow.display();

}

int gamePlayer::setGameState(int state)
{
    gameState = state;
}

int gamePlayer::isGameOver()
{
    if (gameState == 2)
    {
        return true;
    } else {
        return false;
    }
}

int gamePlayer::isGameNew()
{
    if (gameState == 0)
    {
        return true;
    } else {
        return false;
    }
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

void gamePlayer::updateView()
{
    playerWindow.clear(sf::Color::Black);


    while (isGameOver() == true)
    {
        if (playerScore == 11)
        {
            displayGameOver(playerWindow, 1);
        } else if (enemyScore == 11) {
            displayGameOver(playerWindow, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            setGameState(1);
            playerScore = 0;
            enemyScore = 0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            playerWindow.close();
        }
    }

    while (isGameNew() == true)
    {
        displayGameNew(playerWindow);
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                setGameState(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                playerWindow.close();
            }
        }
    }

    playerPaddle -> updateView(playerWindow);
    aiPaddle -> updateView(playerWindow);
    theGameBall -> updateView(playerWindow);
    paintScore(playerWindow);

    playerWindow.display();
}
