#ifndef DARK_RITUAL_H
#define DARK_RITUAL_H

#include "../ritual_card.h"

class DarkRitual:public RitualCard{
        bool active = false;
    public:
        DarkRitual(Player *player);
        void play(GameState *gameState);
        void play(GameState *gameState, int p, std::string t);
        void deactivate();
        void applyEffects();
        void startObserving(GameState *gameState);
        void notify(RawPtrSubject<Event> &whoFrom);
        ~DarkRitual();
};

#endif
