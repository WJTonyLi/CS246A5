#include "../triggered_effect.h"
#include "../base_minion_card.h"

class BoneGolemEffect: public TriggeredEffect{
        bool isActive = false;
    public:
        BoneGolemEffect();
        void activate(GameState *gameState);
        void deactivate();
        void notify(RawPtrSubject<Event> &whoFrom);
        ~BoneGolemEffect();
};
