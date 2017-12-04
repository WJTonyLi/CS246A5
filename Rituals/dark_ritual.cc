#include "dark_ritual.h"

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::invalid_argument;

DarkRitual::DarkRitual(Player *player):RitualCard("Dark Ritual", 0, player, "At the start of your turn, gain 1 magic", 1, 5){}

void DarkRitual::applyEffects(){
    getOwner()->setMagic(getOwner()->getMagic() + 1);
}

void DarkRitual::play(GameState *gameState){
    shared_ptr<DarkRitual> copyOfSelf = make_shared<DarkRitual>(*this);
    getOwner()->setRitual(copyOfSelf);
    getOwner()->attach(copyOfSelf.get());
    copyOfSelf->active = true;
}

void DarkRitual::play(GameState *gameState, int p, string t){
    throw invalid_argument("Rituals are not targeted cards");
}

void DarkRitual::deactivate(){
    active = false;
    getOwner()->detach(this);
}

void DarkRitual::notify(RawPtrSubject<Event> &whoFrom){
    if(active && whoFrom.getInfo().getEventType() == EventType::BEGINNING_TURN){
        conditionMet();
    }
}

DarkRitual::~DarkRitual(){}
