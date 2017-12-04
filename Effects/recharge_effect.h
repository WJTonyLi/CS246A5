#ifndef RECHARGE_EFFECT_H
#define RECHARGE_EFFECT_H

#include <string>
#include "../activated_effect.h"

class RechargeEffect: public ActivatedEffect{
    public:
        RechargeEffect();
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~RechargeEffect();
};

#endif
