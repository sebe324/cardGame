#ifndef DECK_H
#define DECK_H

#include <SFML/Graphics.hpp>

struct Card{
int colorId;
int value;
};
class Deck : public sf::Transformable, public sf::Drawable{
    public:
        sf::Texture *texture;
        sf::VertexArray mVertices;
        std::vector<Card> cards;
        Deck(std::vector<Card> c, sf::Texture &txt, int vis);
        int visibility;
        void deal(Deck &d2, int amount);
        void print();
        void shuffle();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //used to draw all cards
};
#endif // DECK_H
