#include<iostream>
#include<SFML/Graphics.hpp>
#include "include/engine.h"

int main()
{
    Game *ruffini;

    ruffini = new Game(600, 400);

    while(ruffini->window->isOpen())
    {
        ruffini->handleEvent();
        ruffini->update();
        ruffini->render();
    }

}
