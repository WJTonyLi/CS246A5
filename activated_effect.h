#ifndef ACTIVATED_EFFECT_H
#define ACTIVATED_EFFECT_H

#include <string>
#include "game_state.h"

class ActivatedEffect{
        std::string description;
    public:
        ActivatedEffect(std::string description);
        virtual void activate(GameState *GameState) = 0;
        virtual std::string getDescription() = 0;
        virtual ~ActivatedEffect();
};

#endif
