#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gamePlayer.h"

class gameLogic
{
    public:
        gameLogic();
        void checkPaddleBoundaries(gamePlayer* playerWindow);
        int checkWallBoundaries(gamePlayer* playerWindow);
        int getPlayerScore();
        int getEnemyScore();
        void updateView();

    protected:

    private:
        int playerScore;
        int enemyScore;
};

#endif // GAMELOGIC_H
