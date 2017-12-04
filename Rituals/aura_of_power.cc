#include "aura_of_power.h"

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::invalid_argument;

AuraOfPower::AuraOfPower(Player *player):RitualCard("Aura Of Power", 1, player, "Whenever a minion enters play under your control, it gains +1/+1", 2, 4){}

void AuraOfPower::applyEffects(){
    minion->setAttack(minion->getAttack() + 1);
    minion->setDefense(minion->getDefense() + 1);
}

void AuraOfPower::play(GameState *gameState){
    shared_ptr<AuraOfPower> copyOfSelf = make_shared<AuraOfPower>(*this);
    getOwner()->setRitual(copyOfSelf);
    getOwner()->attach(copyOfSelf.get());
    copyOfSelf->active = true;
}

void AuraOfPower::play(GameState *gameState, int p, string t){
    throw invalid_argument("Rituals are not targeted cards");
}

void AuraOfPower::deactivate(){
    active = false;
    getOwner()->detach(this);
}

void AuraOfPower::notify(RawPtrSubject<Event> &whoFrom){
    if(active && whoFrom.getInfo().getEventType() == EventType::MINION_ENTERED){
        minion = whoFrom.getInfo().getMinion();
        conditionMet();
    }
}

AuraOfPower::~AuraOfPower(){}
