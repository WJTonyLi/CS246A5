#include "standstill.h"
#include <iostream>

using namespace std;

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::invalid_argument;

Standstill::Standstill(Player *player):RitualCard("Standstill", 3, player, "Whenever a minion enters play, destroy it", 2, 4){}

void Standstill::applyEffects(){
    minion->setDefense(0);
    for(int x = 0; x < int(minion->getOwner()->getField().size()); x++){
        if(minion->getOwner()->getField().at(x)->isDead()){
            minion->getOwner()->moveToGraveyard(x);
        }
    }
}

void Standstill::play(GameState *gameState){
    shared_ptr<Standstill> copyOfSelf = make_shared<Standstill>(*this);
    gameState->getPlayer1()->setRitual(copyOfSelf);
    gameState->getPlayer1()->attach(copyOfSelf.get());
    gameState->getPlayer2()->attach(copyOfSelf.get());
    copyOfSelf->active = true;
}

void Standstill::play(GameState *gameState, int p, string t){
    throw invalid_argument("Rituals are not targeted cards");
}

void Standstill::deactivate(){
    active = false;
    getOwner()->detach(this);
}

void Standstill::notify(RawPtrSubject<Event> &whoFrom){
    if(active && whoFrom.getInfo().getEventType() == EventType::MINION_ENTERED){
        minion = whoFrom.getInfo().getMinion();
        conditionMet();
    }
}

Standstill::~Standstill(){}
