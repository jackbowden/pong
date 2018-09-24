#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include "gamePaddle.h"

#include <SFML/Graphics.hpp>

class gamePlayer
{
    public:
        sf::RenderWindow playerWindow;
        gamePlayer();
        void updateView();

        gamePaddle* playerPaddle;
        gamePaddle* aiPaddle;

    protected:

    private:
        float playerLocX = 725;
        float playerLocY = 600;

        float aiLocX = 75;
        float aiLocY = 600;
};

#endif // GAMEPLAYER_H
