#ifndef APPRENTICE_SUMMONER_EFFECT_H
#define APPRENTICE_SUMMONER_EFFECT_H

#include <string>
#include "../activated_effect.h"

class ApprenticeSummonerEffect: public ActivatedEffect{
    Player *player;
    public:
        ApprenticeSummonerEffect(Player *player);
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        std::string getDescription();
        ~ApprenticeSummonerEffect();
};

#endif
