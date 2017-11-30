#ifndef SPELL_CARD_H
#define SPELL_CARD_H

#include <memory>
#include "abstract_card.h"
#include "activated_effect.h"

class SpellCard:public AbstractCard{
        std::shared_ptr<ActivatedEffect> effect;
    public:
        SpellCard(std::string name, int cost, std::shared_ptr<Player> player, std::shared_ptr<ActivatedEffect> effect);
        card_template_t getGraphics();
        ~SpellCard();
};

#endif
