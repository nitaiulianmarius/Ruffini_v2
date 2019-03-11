#include<iostream>

#include"button.h"

namespace bt
{

#define WHITE 255,255,255,255
#define BLACK 0,0,0,255
#define RED 255,0,0,255
#define GREEN 0,255,0,255
#define BLUE 0,0,255,255
#define YELLOW 255,255,0,255
#define ORANGE 255,128,0,255
#define TEAL 0,255,255,255
#define PINK 255,0,255,255

void Button::update(sf::RenderWindow* window,std::vector<stateMachine*>& currentState)
{
    sf::Vector2i mouseCoordinate = sf::Mouse::getPosition(*window);
    int x1, y1;

    x1 = mouseCoordinate.x;
    y1 = mouseCoordinate.y;

    if (x < x1 && x1 < x + width && y < y1 && y1 < y + height)
    {
        color = sf::Color(RED);
        state = pState;
    }

    else
    {
        color = sf::Color(WHITE);
        state = nState;
    }
    text.setPosition(x, y);
}

void Button::render(sf::RenderWindow*& window)
{
    if(state == pState)
    {
        sf::RectangleShape rectangle(sf::Vector2f(width,height));
        rectangle.setPosition(x,y);
        rectangle.setFillColor(sf::Color(0,0,0,20));
        window->draw(rectangle);
    }


    text.setColor(color);
    window->draw(text);
}

} //namespace
