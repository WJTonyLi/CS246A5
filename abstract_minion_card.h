#ifndef ABSTRACT_MINION_CARD_H
#define ABSTRACT_MINION_CARD_H

#include <memory>
#include "abstract_card.h"

class AbstractMinionCard:public AbstractCard{
        int attack;
        int defense;
    public:
        AbstractMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense);
        virtual ~AbstractMinionCard();
        virtual void attackEnemy(Player& player);
        virtual void attackEnemy(AbstractMinionCard& minion);
};

#endif
