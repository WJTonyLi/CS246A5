#include "blizzard_effect.h"
#include "../abstract_minion_card.h"

BlizzardEffect::BlizzardEffect():ActivatedEffect{"Does nothing."}{}

void BlizzardEffect::activate(GameState *GameState){
    for(auto it : GameState->getPlayer1()->getField()){
        it->setDefense(it->getDefense() - 2);
    }
    for(auto it : GameState->getPlayer2()->getField()){
        it->setDefense(it->getDefense() - 2);
    }
}

BlizzardEffect::~BlizzardEffect(){}
