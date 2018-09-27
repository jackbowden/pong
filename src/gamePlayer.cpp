#include <SFML/Graphics.hpp>
#include "gamePlayer.h"
#include <iostream>
#include <string>

gamePlayer::gamePlayer() : playerWindow(sf::VideoMode(800,600,32), "Pong, by Jack Bowden", sf::Style::Close) //width by height
{
    playerPaddle = new gamePaddle(725, 600, "Green");
    aiPaddle = new gamePaddle(75, 600, "Yellow");
    theGameBall = new gameBall(400, 300, 7/2, 7/2);
}

void gamePlayer::paintFunnyMode(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf"))
    {
        std::cout << "Error loading font in paintFunnyMode" << std::endl;
    }

    sf::Text displayFunnyModeText;
    displayFunnyModeText.setFont(font);
    displayFunnyModeText.setString("!%$# this! I do what I want!");
    displayFunnyModeText.setCharacterSize(24);
    displayFunnyModeText.setPosition(100,100);
    displayFunnyModeText.setFillColor(sf::Color::Yellow);
    displayFunnyModeText.setStyle(sf::Text::Bold | sf::Text::Italic);

    window.draw(displayFunnyModeText);
}

void gamePlayer::paintScore(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf"))
    {
        std::cout << "Error loading font in paintScore" << std::endl;
    }

    sf::Text displayPlayerScore;
    displayPlayerScore.setFont(font);
    displayPlayerScore.setString("0");
    //!std::cout << playerScore;
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

    theGameBall->resetBall(); //reset the ball non-stop to ensure the game no longer goes on

    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf"))
    {
        std::cout << "Error loading font in displayGameOver" << std::endl;
    }

    playerWindow.clear(sf::Color::Black);

    sf::Text gameOverScreenText;
    gameOverScreenText.setFont(font);
    if (winner == 1)
    {
        gameOverScreenText.setString("Game Over!\nThe player won!\nPress E to enable \"Bad Sport\" Mode\nPress ESC to exit.");
    } else if (winner == 0) {
        gameOverScreenText.setString("Game Over!\nThe AI won!\nPress E to enable \"Bad Sport\" Mode\nPress ESC to exit.");
    } else {
        gameOverScreenText.setString("Game Ended!\nPress E to enable \"Bad Sport\" Mode\nPress ESC to exit.");
    }
    gameOverScreenText.setCharacterSize(24);
    gameOverScreenText.setPosition(300,300);
    gameOverScreenText.setFillColor(sf::Color::White);
    gameOverScreenText.setStyle(sf::Text::Bold);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        playerScore = 0;
        enemyScore = 0;
        setGameState(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        playerWindow.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        funnyMode = true;
        playerScore = 0;
        enemyScore = 0;
        setGameState(1);
    }

    window.draw(gameOverScreenText);
    playerWindow.display();

}

void gamePlayer::displayGameNew(sf::RenderWindow& window)
{
    theGameBall->resetBall(); //reset the ball non-stop to ensure the game doesn't start without me

    sf::Font font;
    if (!font.loadFromFile("assets/sansation.ttf"))
    {
        std::cout << "Error loading font in displayNewGame" << std::endl;
    }

    playerWindow.clear(sf::Color::Black);

    sf::Text gameOverScreenText;
    gameOverScreenText.setFont(font);
    gameOverScreenText.setString("Welcome!\nPress up arrow to play normal\nPress E to enable \"Bad Sport\" Mode\nPress ESC to exit.");
    gameOverScreenText.setCharacterSize(24);
    gameOverScreenText.setPosition(300,300);
    gameOverScreenText.setFillColor(sf::Color::White);
    gameOverScreenText.setStyle(sf::Text::Bold);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        setGameState(1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        playerWindow.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        funnyMode = true;
        setGameState(1);
    }

    window.draw(gameOverScreenText);
    playerWindow.display();

}

int gamePlayer::getFunnyMode()
{
    return funnyMode;
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
    } else if (player == 2) {
        enemyScore++;
    }
}

void gamePlayer::acceptInput(gamePlayer* playerWindow, float delta)
{
    if (gameState == 1) //we cover input needs at all the other menu screens
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            playerWindow -> playerPaddle -> movePaddleUp(delta);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            playerWindow -> playerPaddle -> movePaddleDown(delta);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        {
            setGameState(2);
        }
    }
}

void gamePlayer::updateView()
{
    if (isGameOver() == true)
    {
        if (playerScore == 11)
        {
            displayGameOver(playerWindow, 1);
        } else if (enemyScore == 11) {
            displayGameOver(playerWindow, 0);
        } else if ((enemyScore != 11) && (playerScore != 11)) {
            displayGameOver(playerWindow, 2);
        }
    } else if (isGameNew() == true)
    {
        displayGameNew(playerWindow);
    }
    else
    {
        playerPaddle -> updateView(playerWindow);
        aiPaddle -> updateView(playerWindow);
        theGameBall -> updateView(playerWindow);
        paintScore(playerWindow);

        if (getFunnyMode() == true)
        {
            paintFunnyMode(playerWindow);
        }

        playerWindow.display();
    }
}
