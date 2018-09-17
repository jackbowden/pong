#include <SFML/Graphics.hpp>

#include "viewPlayer.h"
#include "viewAI.h"

int main(int argc, char** argv)
{
  // create main window and prevent it from being resized
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong, by Jack Bowden", sf::Style::Close);

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    // clear screen and fill with black
    App.clear(sf::Color::Black);

    // display
    App.display();
  }

  // Done.
  return 0;
}
