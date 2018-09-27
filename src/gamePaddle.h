#ifndef GAMEPADDLE_H
#define GAMEPADDLE_H
#include <SFML/Graphics.hpp>

#include <string>

class gamePaddle
{
    public:
        gamePaddle();
        gamePaddle(float x, float y, std::string color);

        void updateView(sf::RenderWindow& window);
        void movePaddleUp(float delta);
        void movePaddleDown(float delta);
        void movePaddleLeft(float delta);
        void movePaddleRight(float delta);

        sf::RectangleShape Paddle;

    protected:

    private:
        float x;
        float y;
        std::string color;
};

#endif // GAMEPADDLE_H
