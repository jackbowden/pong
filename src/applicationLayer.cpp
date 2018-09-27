#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "gameLogic.h"
#include "gamePlayer.h"
#include "gameAI.h"
#include "gameBall.h"
#include "gamePaddle.h"

#include <iostream>

int main(int argc, char** argv)
{
    gameAI* aiOperation = new gameAI();
    gameLogic* gameOperation = new gameLogic();
    gamePlayer* playerWindow = new gamePlayer();

    sf::Texture texture;
    texture.loadFromFile("assets/wmcypher.jpg");
    sf::Sprite sprite;
    sf::Vector2u size = texture.getSize();
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(size.x / 2, size.y / 2));
    sprite.setPosition(sf::Vector2f(size.x / 2, size.y / 2));


    playerWindow -> playerWindow.display();

    while(playerWindow -> playerWindow.isOpen())
    {
        sf::Event Event;
        while(playerWindow -> playerWindow.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                playerWindow -> playerWindow.close();
                return 0;
            }

        }

        sf::Clock clock;
        float delta = clock.getElapsedTime().asSeconds() * 100000;
        clock.restart(); //! do i need this?

        playerWindow -> theGameBall -> moveBall(delta);
        gameOperation -> checkWallBoundaries(playerWindow);
        gameOperation -> checkPaddleBoundaries(playerWindow);

        aiOperation -> movePaddle(playerWindow, delta);
        playerWindow->acceptInput(playerWindow, delta);

        playerWindow->playerWindow.draw(sprite);

        playerWindow -> updateView();

    };

    delete aiOperation;
    delete playerWindow;
    delete gameOperation;

  // Done.
  return 0;
}
