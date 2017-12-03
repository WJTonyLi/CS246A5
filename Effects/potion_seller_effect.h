#ifndef POTION_SELLER_EFFECT_H
#define POTION_SELLER_EFFECT_H

#include "../triggered_effect.h"
#include "../base_minion_card.h"

class PotionSellerEffect: public TriggeredEffect{
        bool isActive = false;
    public:
        PotionSellerEffect();
        void activate(GameState *gameState);
        void deactivate();
        void notify(RawPtrSubject<Event> &whoFrom);
        ~PotionSellerEffect();
};

#endif
