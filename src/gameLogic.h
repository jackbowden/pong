#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Audio.hpp>

#include "gamePlayer.h"

class gameLogic
{
    public:
        gameLogic();
        void checkPaddleBoundaries(gamePlayer* playerWindow);
        int checkWallBoundaries(gamePlayer* playerWindow);
        void updateView();

    protected:

    private:
        sf::SoundBuffer ballSoundBuffer;
        sf::SoundBuffer wooshSoundBuffer;

        sf::Sound ballSound;
        sf::Sound wooshSound;

        int playerScore = 0;
        int enemyScore = 0;
        int gameHeight = 600;
        int gameWidth = 800;
};

#endif // GAMELOGIC_H
