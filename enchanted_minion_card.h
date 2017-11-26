#ifndef ENCHANTED_MINION_CARD_H
#define ENCHANTED_MINION_CARD_H

#include "memory.h"
#include "abstract_minion_card.h"

class EnchantedMinionCard:public AbstractMinionCard{
        std::shared_ptr<AbstractMinionCard> minion;
    public:
        EnchantedMinionCard(std::shared_ptr<AbstractMinionCard> minion);
        virtual ~EnchantedMinionCard();
};

#endif
