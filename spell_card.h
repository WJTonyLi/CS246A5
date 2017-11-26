#ifndef SPELL_CARD_H
#define SPELL_CARD_H

#include <memory>
#include "abstract_card.h"
#include "activated_effect.h"

class SpellCard:public AbstractCard{
        std::shared_ptr<ActivatedEffect> effect;
    public:
        SpellCard();
        ~SpellCard();
};

#endif
