#include "potion_seller_effect.h"

using std::shared_ptr;

PotionSellerEffect::PotionSellerEffect():TriggeredEffect{"At the end of your turn, all your minions gain +0/+1."}{}

void PotionSellerEffect::activate(GameState *gameState){
    gameState->getCurrentPlayer()->attach(this);
    isActive = true;
}

void PotionSellerEffect::deactivate(){
    isActive = false;
}

void PotionSellerEffect::notify(RawPtrSubject<Event> &whoFrom){
    if(isActive && whoFrom.getInfo().getEventType() == EventType::ENDING_TURN){
        for (auto &n: getOwner()->getOwner()->getField()) {
            n->setDefense(n->getDefense() + 1);
        }
    }
}

PotionSellerEffect::~PotionSellerEffect(){}
