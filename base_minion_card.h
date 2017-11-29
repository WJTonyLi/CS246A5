#ifndef BASE_MINION_CARD_H
#define BASE_MINION_CARD_H

#include <memory>
#include "activated_effect.h"
#include "triggered_effect.h"
#include "abstract_minion_card.h"

class BaseMinionCard:public AbstractMinionCard{
        std::shared_ptr<ActivatedEffect> activeAbility;
        std::shared_ptr<TriggeredEffect> triggeredAbility;
    public:
        BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense);
        BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense, std::shared_ptr<ActivatedEffect> activeAbility);
        BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense, std::shared_ptr<TriggeredEffect> triggeredAbility);
        ~BaseMinionCard();
};

#endif
