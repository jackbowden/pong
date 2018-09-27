#ifndef GAMEBALL_H
#define GAMEBALL_H

#include <SFML/Graphics.hpp>

class gameBall
{
    public:
        gameBall(float posX, float posY, float originX, float originY);

        sf::CircleShape objectBall;

        void updateView(sf::RenderWindow& window);
        void moveBall(float delta);
        void invertBallAngle();
        void resetBall();
        float getBallAngle();
        float setBallAngle(float newBallAngle);
        void spawnBall();

    protected:

    private:
        float posX;
        float posY;
        float originX = 400;
        float originY = 300;
        float ballAngle = 0.785;
        float ballSpeed = 10;
        float ballRadius = 7;
        float ballSpeedOverGameTime;
};

#endif // GAMEBALL_H
