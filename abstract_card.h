#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include <memory>
#include <string>
#include "ascii_graphics.h"
#include "player.h"

class GameState;

class AbstractCard{
        std::string name;
        int cost;
        Player *owner;
    public:
        AbstractCard(std::string name, int cost, Player *player);
        std::string getName() const;
        int getCost() const;
        Player *getOwner();
        virtual card_template_t getGraphics() const = 0;
        virtual void play(GameState *gameState) = 0;
        virtual void play(GameState *gameState, int p, int t) = 0;
        virtual ~AbstractCard();
};

#endif
