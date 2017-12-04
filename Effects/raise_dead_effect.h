#ifndef RAISE_DEAD_EFFECT_H
#define RAISE_DEAD_EFFECT_H

#include <string>
#include "../activated_effect.h"

class RaiseDeadEffect: public ActivatedEffect{
    public:
        RaiseDeadEffect();
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~RaiseDeadEffect();
};

#endif
