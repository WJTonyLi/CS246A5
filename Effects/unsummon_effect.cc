#include <sstream>
#include <stdexcept>
#include "unsummon_effect.h"
#include "../abstract_minion_card.h"
#include <iostream>

using namespace std;

using std::string;
using std::shared_ptr;
using std::istringstream;
using std::invalid_argument;

UnsummonEffect::UnsummonEffect():ActivatedEffect{"Return target minion to its owner's hand"}{}

void UnsummonEffect::activate(GameState *gameState){
    throw invalid_argument("Unsummon must target a ritual or minion");
}

void UnsummonEffect::activate(GameState *gameState, int p, std::string t){
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
    istringstream is{t};
    is>>target;
    if(!is.fail()){
        cout<<"WTF "<<p<<" "<<t<<endl;
        player->addCardToHand(player->takeFieldMinion(target - 1));
        cout<<"WTF2 "<<p<<" "<<t<<endl;
    }
    else{
        throw invalid_argument("Target must be the index of a minion");
    }
}

int UnsummonEffect::getCost(){
    return 1;
}

UnsummonEffect::~UnsummonEffect(){}
