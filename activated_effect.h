#ifndef ACTIVATED_EFFECT_H
#define ACTIVATED_EFFECT_H

#include <string>
#include "game_state.h"

class ActivatedEffect{
        std::string description;
    public:
        ActivatedEffect(std::string description);
        virtual void activate(GameState *gameState) = 0;
        virtual void activate(GameState *gameState, int p, std::string t) = 0;
        virtual int getCost() = 0;
        virtual std::string getDescription();
        virtual ~ActivatedEffect();
};

#endif
