#include "Deck.h"
#include <iostream>
Deck::Deck(std::vector<Card> c, sf::Texture &txt, int vis){
    cards=c;
    texture = &txt;
    visibility=vis;
    organise(1000);
}
Deck::Deck(sf::Texture &txt, int vis){
     texture = &txt;
    visibility=vis;
}
Deck::Deck(){}
void Deck::deal(Deck &d2, int amount){
    for(int i=0; i<amount; i++){
    cards.push_back(d2.cards[i]);
    d2.cards.erase(d2.cards.begin());
    organise(1000);
}
}
void Deck::dealAt(Deck &d2 ,int n){
cards.push_back(d2.cards[n]);
d2.cards.erase(d2.cards.begin()+n);
organise(1000);
d2.organise(1000);
}
void Deck::print(){
    for(int i=0; i<cards.size(); i++) std::cout<<cards[i].colorId<<", "<<cards[i].value<<", "<<i<<std::endl;
}
void Deck::shuffle(){
    for(int i=0; i<cards.size(); i++){
        int index=(std::rand()%cards.size());
        int index2=(std::rand()%cards.size());
        Card temp=cards[index];
        cards[index]=cards[index2];
        cards[index2]=temp;
        organise(1000);
    }
}
void Deck::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform*=getTransform();
    sf::Vector2f pos(0,0);
    switch(visibility){
        case 0:{
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setTextureRect(sf::IntRect(0,393,73,98));
            if(cards.size()>1){
                sprite.setPosition(pos);
                target.draw(sprite,states);
                sprite.move(20,20);
                target.draw(sprite,states);
            }
        } break;
        case 1:{
             sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setTextureRect(sf::IntRect(0,393,73,98));
            for(int i=0; i<cards.size(); i++){
        sprite.setPosition(cards[i].pos);
        target.draw(sprite, states);
            }
        } break;
        case 2:{
             sf::Sprite sprite;
        sprite.setTexture(*texture);
    for(int i=0; i<cards.size(); i++){
         sf::RectangleShape shape(sf::Vector2f(100.f,100.f));
    shape.setFillColor(sf::Color::Red);
        sprite.setTextureRect(sf::IntRect((cards[i].value-1)*73,cards[i].colorId*98,73,98));
        sprite.setPosition(cards[i].pos);
        target.draw(sprite, states);
    }
    }break;
    }
}
void Deck::organise(int width){
    sf::Vector2f pos(0.f,0.f);
for(int i=0; i<cards.size(); i++){
        if(pos.x+80>width){
            pos.x=getPosition().x;
            pos.y+=105.f;
        }
        cards[i].pos=sf::Vector2f(pos.x,pos.y);
        pos.x+=80.f;
}
}
