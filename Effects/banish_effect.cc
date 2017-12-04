#include <sstream>
#include <stdexcept>
#include "banish_effect.h"
#include "../abstract_minion_card.h"

using std::string;
using std::shared_ptr;
using std::istringstream;
using std::invalid_argument;

BanishEffect::BanishEffect():ActivatedEffect{"Destroy target minion or ritual"}{}

void BanishEffect::activate(GameState *gameState){
    throw invalid_argument("Banish must target a ritual or minion");
}

void BanishEffect::activate(GameState *gameState, int p, std::string t){
    shared_ptr<Player> player;
    if(p == 1){
        player = gameState->getPlayer1();
    }
    else if(p == 2){
        player = gameState->getPlayer2();
    }
    else{
        throw invalid_argument("Player must be 1 or 2");
    }
    int target;
    if(t == "r"){
        player->removeRitual();
    }
    else{
        istringstream is{t};
        is>>target;
        if(!is.fail()){
            player->getField().at(target - 1)->setDefense(0);
            player->moveToGraveyard(target - 1);
        }
        else{
            throw invalid_argument("Target must be r or the index of a minion");
        }
    }
}

int BanishEffect::getCost(){
    return 3;
}

BanishEffect::~BanishEffect(){}
