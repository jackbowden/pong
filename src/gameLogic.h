#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gamePlayer.h"

class gameLogic
{
    public:
        gameLogic();
        void moveBall(gamePlayer* playerWindow, float delta);

    protected:

    private:
        int ballLocX;
        int ballLocY;
};

#endif // GAMELOGIC_H
