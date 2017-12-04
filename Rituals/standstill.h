#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "../ritual_card.h"
#include "../abstract_minion_card.h"

class Standstill:public RitualCard{
        bool active = false;
        std::shared_ptr<AbstractMinionCard> minion;
    public:
        Standstill(Player *player);
        void play(GameState *gameState);
        void play(GameState *gameState, int p, std::string t);
        void deactivate();
        void applyEffects();
        void startObserving(GameState *gameState);
        void notify(RawPtrSubject<Event> &whoFrom);
        ~Standstill();
};

#endif
