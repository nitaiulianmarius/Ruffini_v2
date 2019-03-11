#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <windows.h>
#include "stateMachine.h"
#include "menuState.h"

class Game
{
public:

    Game(int _width, int _height):
    width(_width),
    height(_height)
    {
        window = new sf::RenderWindow(sf::VideoMode(width, height),"Ruffini v2", sf::Style::Fullscreen);
        window->setFramerateLimit(60);
        myState.push_back(new menuState(window));
    };

    void handleEvent(){ myState[myState.size()-1]->handleEvent(window, myState); };
    void update(){ myState[myState.size()-1]->update(window, myState); };
    void render(){ window->clear();myState[myState.size()-1]->render(window);window->display(); };
    void outtextxy(sf::RenderWindow*& window, int x, int y, sf::String string, sf::Color color = { 0, 0, 0, 255 }, int size = 14)
    {
        text.setPosition(x, y);
        text.setString(string);
        text.setColor(color);
        text.setCharacterSize(size);
        window->draw(text);
    };

    int width, height;
    std::vector<stateMachine*> myState;
    sf::RenderWindow *window;
    sf::Event event;
    sf::Font font;
    sf::Text text;
};

#endif // ENGINE_H
