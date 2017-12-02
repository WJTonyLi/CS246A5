#include "blizzard_effect.h"
#include "../abstract_minion_card.h"

using std::shared_ptr;

BlizzardEffect::BlizzardEffect():ActivatedEffect{"Does nothing."}{}

void BlizzardEffect::activate(GameState *gameState){
    shared_ptr<Player> p1 = gameState->getPlayer1();
    for(int x = 0; x < p1->getField().size(); x++){
        shared_ptr<AbstractMinionCard> currentMinion = p1->getField().at(x);
        currentMinion->setDefense(currentMinion->getDefense() - 2);
        if(p1->getField().at(x)->isDead()){
            p1->moveToGraveyard(x);
        }
    }
    shared_ptr<Player> p2 = gameState->getPlayer2();
    for(int x = 0; x < p2->getField().size(); x++){
        shared_ptr<AbstractMinionCard> currentMinion = p2->getField().at(x);
        currentMinion->setDefense(currentMinion->getDefense() - 2);
        if(p2->getField().at(x)->isDead()){
            p2->moveToGraveyard(x);
        }
    }
}

BlizzardEffect::~BlizzardEffect(){}
