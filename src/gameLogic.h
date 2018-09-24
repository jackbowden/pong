#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gamePlayer.h"

class gameLogic
{
    public:
        gameLogic();
        void checkPaddleBoundaries();
        int checkWallBoundaries();

    protected:

    private:
};

#endif // GAMELOGIC_H
