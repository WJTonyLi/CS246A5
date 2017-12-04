#ifndef UNSUMMON_EFFECT_H
#define UNSUMMON_EFFECT_H

#include <string>
#include "../activated_effect.h"

class UnsummonEffect: public ActivatedEffect{
    public:
        UnsummonEffect();
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~UnsummonEffect();
};

#endif
