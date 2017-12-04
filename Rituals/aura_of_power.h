#ifndef AURA_OF_POWER_H
#define AURA_OF_POWER_H

#include "../ritual_card.h"
#include "../abstract_minion_card.h"

class AuraOfPower:public RitualCard{
        bool active = false;
        std::shared_ptr<AbstractMinionCard> minion;
    public:
        AuraOfPower(Player *player);
        void play(GameState *gameState);
        void play(GameState *gameState, int p, std::string t);
        void deactivate();
        void applyEffects();
        void startObserving(GameState *gameState);
        void notify(RawPtrSubject<Event> &whoFrom);
        ~AuraOfPower();
};

#endif
