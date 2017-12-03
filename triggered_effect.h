#ifndef TRIGGERED_EFFECT_H
#define TRIGGERED_EFFECT_H

#include "player.h"
#include "raw_ptr_observer.h"
#include "game_state.h"

class TriggeredEffect:public RawPtrObserver<Event>{
    protected:
        std::shared_ptr<AbstractMinionCard> owner;
        TriggeredEffect *getThis();
    public:
        TriggeredEffect();
        virtual void activate(GameState * gameState) = 0;
        virtual void deactivate() = 0;
        virtual void notify(RawPtrSubject<Event> &whoFrom) = 0;
        void setOwner(std::shared_ptr<AbstractMinionCard> owner);
        std::shared_ptr<AbstractMinionCard> getOwner();
        virtual ~TriggeredEffect();
};

#endif
