#ifndef GAMEBALL_H
#define GAMEBALL_H

#include <SFML/Graphics.hpp>

class gameBall
{
    public:
        gameBall();
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
        float ballAngle = 0.f;
        float ballSpeed = 10.f;
        float ballRadius = 7;
};

#endif // GAMEBALL_H
