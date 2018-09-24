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
};

#endif // GAMELOGIC_H
