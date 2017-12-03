#include <stdexcept>
#include "blizzard_effect.h"
#include "../abstract_minion_card.h"

using std::string;
using std::shared_ptr;
using std::invalid_argument;

BlizzardEffect::BlizzardEffect():ActivatedEffect{"Deal 2 damage to all minions"}{}

void BlizzardEffect::activate(GameState *gameState){
    shared_ptr<Player> p1 = gameState->getPlayer1();
    for(int x = 0; x < int(p1->getField().size());){
        shared_ptr<AbstractMinionCard> currentMinion = p1->getField().at(x);
        currentMinion->setDefense(currentMinion->getDefense() - 2);
        if(p1->getField().at(x)->isDead()){
            p1->moveToGraveyard(x);
        }
        else{
            x++;
        }
    }
    shared_ptr<Player> p2 = gameState->getPlayer2();
    for(int x = 0; x < int(p2->getField().size());){
        shared_ptr<AbstractMinionCard> currentMinion = p2->getField().at(x);
        currentMinion->setDefense(currentMinion->getDefense() - 2);
        if(p2->getField().at(x)->isDead()){
            p2->moveToGraveyard(x);
        }
        else{
            x++;
        }
    }
}

void BlizzardEffect::activate(GameState *gameState, int p, std::string t){
    throw invalid_argument("Blizzard is not a targeted spell.");
}

int BlizzardEffect::getCost(){
    return 3;
}

BlizzardEffect::~BlizzardEffect(){}
