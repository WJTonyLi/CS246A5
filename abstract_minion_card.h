#ifndef ABSTRACT_MINION_CARD_H
#define ABSTRACT_MINION_CARD_H

#include <memory>
#include <string>
#include "abstract_card.h"
#include "game_state.h"

class AbstractMinionCard:public AbstractCard{
        int attack;
        int defense;
        int originalAttack;
        int originalDefense;
    public:
        AbstractMinionCard(std::string name, int cost, Player *player, int attack, int defense);
        int getAttack() const;
        void setAttack(int value);
        int getDefense() const;
        void setDefense(int value);
        virtual void attackEnemy(GameState *gameState);
        virtual void attackEnemy(AbstractMinionCard& minion);
        virtual void play(GameState *gameState) = 0;
        virtual void play(GameState *gameState, int p, std::string t) = 0;
        virtual card_template_t getGraphics() const override = 0;
        virtual ~AbstractMinionCard();
};

#endif
