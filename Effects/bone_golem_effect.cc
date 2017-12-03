#include "bone_golem_effect.h"

using std::shared_ptr;

BoneGolemEffect::BoneGolemEffect():TriggeredEffect{"Gains +1/+1 whenever a minion leaves play."}{}

void BoneGolemEffect::activate(GameState *gameState){
    gameState->getPlayer1()->attach(this);
    gameState->getPlayer2()->attach(this);
    isActive = true;
}

void BoneGolemEffect::deactivate(){
    isActive = false;
}

void BoneGolemEffect::notify(RawPtrSubject<Event> &whoFrom){
    if(isActive && whoFrom.getInfo().getEventType() == EventType::MINION_LEFT){
        getOwner()->setAttack(getOwner()->getAttack() + 1);
        getOwner()->setDefense(getOwner()->getDefense() + 1);
    }
}

BoneGolemEffect::~BoneGolemEffect(){}
