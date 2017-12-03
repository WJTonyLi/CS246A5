#ifndef BLIZZARD_EFFECT_H
#define BLIZZARD_EFFECT_H

#include <string>
#include "../activated_effect.h"

class BlizzardEffect: public ActivatedEffect{
    public:
        BlizzardEffect();
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        ~BlizzardEffect();
};

#endif
