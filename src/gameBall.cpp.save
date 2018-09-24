#include "gameBall.h"

gameBall::gameBall(float posX, float posY, float originX, float originY)
{
    objectBall.setRadius(7);
    objectBall.setOutlineThickness(3);
    objectBall.setOutlineColor(sf::Color::Black);
    objectBall.setOrigin(originX, originY);
    objectBall.setPosition(posX, posY);
    objectBall.setPointCount(50);
    objectBall.setFillColor(sf::Color::White);
}

void gameBall::updateView(sf::RenderWindow& window)
{
    window.draw(objectBall);
}
