#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

#include <SFML/Graphics.hpp>

class gamePlayer
{
    public:
        sf::RenderWindow playerWindow;
        gamePlayer();
        void updateView();

    protected:

    private:
};

#endif // GAMEPLAYER_H
