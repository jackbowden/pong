#include <SFML/Graphics.hpp>
#include "gamePlayer.h"


gamePlayer::gamePlayer() : playerWindow(sf::VideoMode(800,600,32), "Pong, by Jack Bowden", sf::Style::Close) //width by height
{
    //ctor
}

void gamePlayer::updateView() //refreshes screen with new content
{
    playerWindow.clear(sf::Color::Black);
    playerWindow.display();
}
