#include <algorithm>
#include <stdexcept>
#include <sstream>
#include "novice_pyromancer_effect.h"
#include "../base_minion_card.h"

using std::min;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::istringstream;
using std::invalid_argument;

NovicePyromancerEffect::NovicePyromancerEffect(Player *player):ActivatedEffect{"Deal 1 damage to target minion"}, player{player}{}

void NovicePyromancerEffect::activate(GameState *gameState){
    throw invalid_argument("This is a targeted ability.");
}

void NovicePyromancerEffect::activate(GameState *gameState, int p, std::string t){
    shared_ptr<Player> player;
    if(p == 1){
        player = gameState->getPlayer1();
    }
    else if(p == 2){
        player = gameState->getPlayer2();
    }
    else{
        throw invalid_argument("Must target player 1 or 2.");
    }
    int target;
    istringstream (t)>>target;
    if(target >= 1 && target <= int(player->getField().size())){
        shared_ptr<AbstractMinionCard> currentMinion = player->getField().at(target - 1);
        currentMinion->setDefense(currentMinion->getDefense() - 1);
        if(player->getField().at(target - 1)->isDead()){
            player->moveToGraveyard(target - 1);
        }
    }
    else{
        throw invalid_argument("Must target a minion.");
    }
}

int NovicePyromancerEffect::getCost(){
    return 1;
}

NovicePyromancerEffect::~NovicePyromancerEffect(){}
