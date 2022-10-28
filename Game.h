#ifndef GAME_H
#define GAME_H
#include "Deck.h"
class Game : public sf::Drawable {
    public:
        Deck d1;
        Deck d2;
        Deck cardsLeft;
        Deck currentCards;
        Game(std::string path);
        sf::Texture texture;
        void selectCard(sf::Vector2i mousePos);
    private:
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
#endif // GAME_H
