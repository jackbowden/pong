#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include "gamePaddle.h"
#include "gameBall.h"

#include <SFML/Graphics.hpp>

class gamePlayer
{
    public:
        sf::RenderWindow playerWindow;
        gamePlayer();
        void updateView();
        void paintScore(sf::RenderWindow& window);
        void setScore(int player);
        int isGameOver();
        int isGameNew();
        int setGameState(int state);
        void displayGameOver(sf::RenderWindow& window, int winner);
        void displayGameNew(sf::RenderWindow& window);
        int getFunnyMode();
        void paintFunnyMode(sf::RenderWindow& window);
        void acceptInput(gamePlayer* playerWindow, float delta);

        gamePaddle* playerPaddle;
        gamePaddle* aiPaddle;
        gameBall* theGameBall;

    protected:

    private:
        float playerLocX = 725;
        float playerLocY = 600;

        float aiLocX = 75;
        float aiLocY = 600;

        float ballLocX = 400;
        float ballLocY = 300;

        float ballOriginX = 7 / 2;
        float ballOriginY = 7 / 2;

        int playerScore = 0;
        int enemyScore = 0;

        int gameState = 0;
        int funnyMode = false;

};

#endif // GAMEPLAYER_H
