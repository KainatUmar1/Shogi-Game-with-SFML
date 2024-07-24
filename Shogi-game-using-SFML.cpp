#include<iostream>
#include<conio.h>
#include"Chess.h"
using namespace std;

#include <SFML/Graphics.hpp>
// Function to get the position on screen by mouse
void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i p = sf::Mouse::getPosition(window);

            cpos = p.x;
            rpos = p.y;
            break;
        }
    }
}

// Function to print image on screen
void print(sf::RenderWindow& window,int r,int c)
{
    sf::Texture temp;
    if (!temp.loadFromFile("img.jpg"))  //  img ==> file name for image
    {
        throw("Unable to load img");
    }

    sf::Sprite s(temp);
    s.setScale(1, 1); //  (width and heigth of image to be printed)

    s.setPosition(r,c); // position of image
    window.draw(s);	// draw() will only draw image on backend, image will not display on screen
    window.display();  // display() will show image on screen
}

int main1()
{
    sf::RenderWindow window(sf::VideoMode(1300, 700), "Chessboard");
    sf::RectangleShape tile(sf::Vector2f(60.f, 60.f));
    tile.setFillColor(sf::Color::White);

    for (int row = 1; row <= 8; row++) 
    {
        for (int col = 1; col <= 8; col++) 
        {
            if ((row + col) % 2 == 0) 
                tile.setFillColor(sf::Color::White);
            else 
                tile.setFillColor(sf::Color::Black);

            tile.setPosition(col * 60.f, row * 60.f);

            window.draw(tile);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }

    return 0;

}

int main()
{
	Chess s;
	s.play();
	return 0;
}