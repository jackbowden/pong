#ifndef GAMEAI_H
#define GAMEAI_H

#include "gamePlayer.h"

class gameAI
{
    public:
        gameAI();
        void movePaddle(gamePlayer* playerWindows, float delta);

    protected:

    private:
        float setSpeed = 200.f;
        float paddleSpeed = 0.f;
        float gameHeight = 800;
};

#endif // GAMEAI_H
