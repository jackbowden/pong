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

    protected:

    private:
        float posX;
        float posY;
        float originX;
        float originY;
};

#endif // GAMEBALL_H
