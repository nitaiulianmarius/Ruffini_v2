#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>
#include"stateMachine.h"

namespace bt
{

#define nState 0
#define pState 1

class Button
{
public:

    Button();
    Button(int newX,int newY, int newWidth, int newHeight, sf::Font newFont, sf::String newString, int sizeS):
    x(newX),
    y(newY),
    width(newWidth),
    height(newHeight),
    font(newFont),
    mString(newString),
    sizeString(sizeS)
    {
        text.setString(mString);
        text.setFont(font);
        text.setCharacterSize(sizeString);
        text.setPosition(x, y);
    };

    int x, y;
    int width, height;
    int state;
    int sizeString;

    sf::String mString;
    sf::Text text;
    sf::Color color;
    sf::Font font;

    void update(sf::RenderWindow*, std::vector<stateMachine*>&);
    void render(sf::RenderWindow*&);
};

} // namespace

#endif // BUTTON_H
