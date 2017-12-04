#include <stdexcept>
#include "raise_dead_effect.h"
#include "../abstract_minion_card.h"

using std::string;
using std::shared_ptr;
using std::invalid_argument;

RaiseDeadEffect::RaiseDeadEffect():ActivatedEffect{"Deal 2 damage to all minions"}{}

void RaiseDeadEffect::activate(GameState *gameState){
    shared_ptr<AbstractMinionCard> minion = gameState->getCurrentPlayer()->takeGraveyardMinion();
    minion->setDefense(1);
    minion->play(gameState);
}

void RaiseDeadEffect::activate(GameState *gameState, int p, std::string t){
    throw invalid_argument("Blizzard is not a targeted spell.");
}

int RaiseDeadEffect::getCost(){
    return 1;
}

RaiseDeadEffect::~RaiseDeadEffect(){}
