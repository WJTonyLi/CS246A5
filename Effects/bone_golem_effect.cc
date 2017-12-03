#include "bone_golem_effect.h"

using std::shared_ptr;

BoneGolemEffect::BoneGolemEffect(){}

void BoneGolemEffect::activate(GameState *gameState){
    gameState->getPlayer1()->attach(this);
    gameState->getPlayer2()->attach(this);
    isActive = true;
}

void BoneGolemEffect::deactivate(){
    isActive = false;
}

void BoneGolemEffect::notify(RawPtrSubject<Event> &whoFrom){
    if(isActive && whoFrom.getInfo().getEventType() == EventType::MINION_ENTERED){
        getOwner()->setAttack(getOwner()->getAttack() + 1);
        getOwner()->setDefense(getOwner()->getDefense() + 1);
    }
}

BoneGolemEffect::~BoneGolemEffect(){}
