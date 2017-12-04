#include "fire_elemental_effect.h"
#include "../abstract_minion_card.h"

using std::shared_ptr;

FireElementalEffect::FireElementalEffect():TriggeredEffect{"Whenever an opponent's minion enters play, deal 1 damage to it."} {}

void FireElementalEffect::activate(GameState *gameState) {
    gameState->getCurrentOpponent()->attach(this);
    isActive = true;
}

void FireElementalEffect::deactivate() {
    isActive = false;
}

void FireElementalEffect::notify(RawPtrSubject<Event> &whoFrom) {
    if (isActive && whoFrom.getInfo().getEventType() == EventType::MINION_ENTERED) {
        shared_ptr<AbstractMinionCard> targetMinion = whoFrom.getInfo().getMinion();
        targetMinion->setDefense(targetMinion->getDefense() - 1);
        for(int x = 0; x < int(targetMinion->getOwner()->getField().size()); x++){
            if(targetMinion->getOwner()->getField().at(x)->isDead()){
                targetMinion->getOwner()->moveToGraveyard(x);
            }
        }
    }
}

FireElementalEffect::~FireElementalEffect() {}
