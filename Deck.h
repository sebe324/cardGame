#ifndef DECK_H
#define DECK_H

#include <SFML/Graphics.hpp>

struct Card{
int colorId;
int value;
sf::Vector2f pos;
};
class Deck : public sf::Transformable, public sf::Drawable{
    public:
        sf::Texture *texture;
        sf::VertexArray mVertices;
        std::vector<Card> cards;
        Deck(std::vector<Card> c, sf::Texture &txt, int vis);
        Deck(sf::Texture &txt, int vis);
        Deck();
        int visibility;
        void deal(Deck &d2, int amount);
        void print();
        void shuffle();
        void dealAt(Deck &d2 ,int n);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //used to draw all cards
        void organise(int width);
};
#endif // DECK_H
