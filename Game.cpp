#include "Game.h"
#include <iostream>
Game::Game(std::string path){
        if(!texture.loadFromFile("cards.png")) std::cout<<"error";
        d1=Deck(texture,2);
        d2=Deck(texture,1);
        cardsLeft=Deck(texture,0);
        currentCards=Deck(texture,2);
        for(int i=0; i<4; i++){
        for(int j=1; j<=13; j++){
            Card card;
            card.colorId=i;
            card.value=j;
            cardsLeft.cards.push_back(card);
        }
    }
    cardsLeft.shuffle();
    cardsLeft.setPosition(250.f,250.f);
    d1.deal(cardsLeft, 5);
    d1.setPosition(300.f,500.f);
    d2.deal(cardsLeft,5);
    d2.setPosition(300.f,0.f);
    currentCards.deal(cardsLeft,1);
    currentCards.setPosition(400.f,250.f);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const{
target.draw(d1,states);
target.draw(d2,states);
target.draw(cardsLeft, states);
target.draw(currentCards, states);
}
void Game::selectCard(sf::Vector2i mousePos){

for(int i=0; i<d1.cards.size(); i++){
    if(mousePos.x>=d1.cards[i].pos.x+d1.getPosition().x &&
       mousePos.x<=d1.cards[i].pos.x+73+d1.getPosition().x &&
       mousePos.y>=d1.cards[i].pos.y+d1.getPosition().y &&
       mousePos.y<=d1.cards[i].pos.y+98+d1.getPosition().y
       ){
        std::cout<<d1.cards[i].colorId<<", "<<d1.cards[i].value<<", "<<i<<std::endl;
        currentCards.dealAt(d1,i);
       }
}
}
