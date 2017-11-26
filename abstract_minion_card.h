#ifndef ABSTRACT_MINION_CARD_H
#define ABSTRACT_MINION_CARD_H

#include "abstract_card.h"

class AbstractMinionCard:public AbstractCard{
        int attack;
        int defense;
    public:
        AbstractMinionCard(int attack, int defense);
        virtual ~AbstractMinionCard();
};

#endif
