#include <stdexcept>
#include "recharge_effect.h"
#include "../ritual_card.h"
#include "../abstract_minion_card.h"

using std::string;
using std::shared_ptr;
using std::invalid_argument;

RechargeEffect::RechargeEffect():ActivatedEffect{"Your ritual gains 3 charges"}{}

void RechargeEffect::activate(GameState *gameState){
    if(gameState->getCurrentPlayer()->hasRitualInPlay()){
        gameState->getCurrentPlayer()->getRitual()->addCharges(3);
    }
}

void RechargeEffect::activate(GameState *gameState, int p, std::string t){
    throw invalid_argument("Blizzard is not a targeted spell.");
}

int RechargeEffect::getCost(){
    return 1;
}

RechargeEffect::~RechargeEffect(){}
