#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gamePlayer.h"

class gameLogic
{
    public:
        gameLogic();
        void checkPaddleBoundaries(gamePlayer* playerWindow);
        int checkWallBoundaries(gamePlayer* playerWindow);

    protected:

    private:
        int playerScore = 0;
        int enemyScore = 0;
        int hitTop = 0;
        int hitBottom = 0;
};

#endif // GAMELOGIC_H
