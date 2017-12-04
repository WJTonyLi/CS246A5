#include "dark_ritual.h"

using std::string;
using std::make_shared;
using std::invalid_argument;

DarkRitual::DarkRitual(Player *player):RitualCard("Dark Ritual", 0, player, "At the start of your turn, gain 1 magic", 5, 1){}

void DarkRitual::applyEffects(){
    getOwner()->setMagic(getOwner()->getMagic() + 1);
}

void DarkRitual::play(GameState *gameState){
    getOwner()->setRitual(make_shared<DarkRitual>(*this));
    active = true;
}

void DarkRitual::play(GameState *gameState, int p, string t){
    throw invalid_argument("Rituals are not targeted cards");
}

void DarkRitual::deactivate(){
    active = false;
}

void DarkRitual::notify(RawPtrSubject<Event> &whoFrom){
    if(active && whoFrom.getInfo().getEventType() == EventType::BEGINNING_TURN){
        conditionMet();
    }
}

DarkRitual::~DarkRitual(){}
