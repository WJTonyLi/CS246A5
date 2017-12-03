#ifndef NOVICE_PYROMANCER_EFFECT_H
#define NOVICE_PYROMANCER_EFFECT_H

#include <string>
#include "../activated_effect.h"

class NovicePyromancerEffect: public ActivatedEffect{
    Player *player;
    public:
        NovicePyromancerEffect(Player *p);
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~NovicePyromancerEffect();
};

#endif
