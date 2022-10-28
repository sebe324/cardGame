#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Game.h"

int main()
{
srand(time(NULL));
std::string colors[4]={"Pik","Kier", "Karo", "Trefl"};
int colorIds[4]={0,1,2,3};

    Game game("cards.png");
    sf::RenderWindow window(sf::VideoMode(1600, 1000), "Cards");
    window.setVerticalSyncEnabled(true);
    sf::Texture backgroundTxt;
    if(!backgroundTxt.loadFromFile("background.png"));
    sf::Sprite background(backgroundTxt);
   while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type==sf::Event::MouseButtonPressed){
                sf::Vector2i localPosition = sf::Mouse::getPosition(window);
            std::cout<<"x: "<<localPosition.x<<std::endl;
            std::cout<<"y: "<<localPosition.y<<std::endl;
            game.selectCard(localPosition);
            }
        }

       window.clear(sf::Color(33, 140, 116));
       window.draw(background);
       window.draw(game);
        window.display();
    }


   return 0;
}
