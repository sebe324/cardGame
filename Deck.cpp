#include "Deck.h"
#include <iostream>
Deck::Deck(std::vector<Card> c, sf::Texture &txt, int vis){
    cards=c;
    texture = &txt;
    visibility=vis;
}
void Deck::deal(Deck &d2, int amount){
    for(int i=0; i<amount; i++){
    cards.push_back(d2.cards[i]);
    d2.cards.erase(d2.cards.begin());
}
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
    }
}
void Deck::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform*=getTransform();
    sf::Vector2f pos(getPosition().x,getPosition().y);
    switch(visibility){
        case 0:{
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setTextureRect(sf::IntRect(0,393,73,98));
            if(cards.size()>1){
                sprite.setPosition(getPosition().x, getPosition().y);
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
                if(pos.x+80>target.getSize().x){
            pos.x=getPosition().x;
            pos.y+=105.f;
        }
        sprite.setPosition(pos);
        target.draw(sprite, states);
        pos.x+=80.f;
            }
        } break;
        case 2:{
             sf::Sprite sprite;
        sprite.setTexture(*texture);
    for(int i=0; i<cards.size(); i++){
        if(pos.x+80>target.getSize().x){
            pos.x=getPosition().x;
            pos.y+=105.f;
        }

        sprite.setTextureRect(sf::IntRect((cards[i].value-1)*73,cards[i].colorId*98,73,98));
        sprite.setPosition(pos);
        target.draw(sprite, states);
        pos.x+=80.f;
    }
    }break;
    }
}
