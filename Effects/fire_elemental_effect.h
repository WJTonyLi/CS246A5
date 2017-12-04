#ifndef FIRE_ELEMENTAL_EFFECT_H
#define FIRE_ELEMENTAL_EFFECT_H

#include "../triggered_effect.h"
#include "../base_minion_card.h"

class FireElementalEffect: public TriggeredEffect {
    bool isActive = false;
    public:
        FireElementalEffect();
        void activate(GameState *gameState);
        void deactivate();
        void notify(RawPtrSubject<Event> &whoFrom);
        ~FireElementalEffect();
};

#endif
