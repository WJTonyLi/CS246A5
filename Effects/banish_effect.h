#ifndef BANISH_EFFECT_H
#define BANISH_EFFECT_H

#include <string>
#include "../activated_effect.h"

class BanishEffect: public ActivatedEffect{
    public:
        BanishEffect();
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~BanishEffect();
};

#endif
