#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include "gamePlayer.h"
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
        int playerScore = 0;
        int enemyScore = 0;

        int gameState = 0;
        int funnyMode = false;

};

#endif // GAMEPLAYER_H
