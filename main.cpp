#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include "Deck.h"

int main()
{
    sf::Texture texture;
    if(!texture.loadFromFile("cards.png")) std::cout<<"error";
srand(time(NULL));
std::string colors[4]={"Pik","Kier", "Karo", "Trefl"};
int colorIds[4]={0,1,2,3};


   std::vector<Card>cardStack;
    Deck baseCards(cardStack, texture,0);
    for(int i=0; i<4; i++){
        for(int j=1; j<=13; j++){
            Card card;
            card.colorId=i;
            card.value=j;
            baseCards.cards.push_back(card);
        }
    }
    baseCards.shuffle();
    std::vector<Card> c;
    Deck hand1(c,texture,2);
    hand1.deal(baseCards, 5);
    hand1.setPosition(100.f,0.f);
    std::vector<Card> c2;
    Deck hand2(c2, texture,1);
    hand2.deal(baseCards,5);
    hand2.setPosition(100.f,300.f);
    hand1.print();
    hand2.print();
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Cards");
    window.setVerticalSyncEnabled(true);

   while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


       window.clear(sf::Color(33, 140, 116));
        window.draw(hand1);
        window.draw(hand2);
        window.draw(hand2);
        window.display();
    }


   return 0;
}
