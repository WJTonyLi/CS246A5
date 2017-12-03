#ifndef MASTER_SUMMONER_EFFECT_H
#define MASTER_SUMMONER_EFFECT_H

#include <string>
#include "../activated_effect.h"

class MasterSummonerEffect: public ActivatedEffect{
    Player *player;
    public:
        MasterSummonerEffect(Player *player);
        void activate(GameState *gameState);
        void activate(GameState *gameState, int p, std::string t);
        int getCost();
        ~MasterSummonerEffect();
};

#endif
