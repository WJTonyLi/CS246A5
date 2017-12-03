#include <algorithm>
#include <stdexcept>
#include "master_summoner_effect.h"
#include "../base_minion_card.h"

using std::min;
using std::string;
using std::shared_ptr;
using std::make_shared;
using std::invalid_argument;

MasterSummonerEffect::MasterSummonerEffect(Player *player):ActivatedEffect{"Summon up to three 1/1 air elementals"}, player{player}{}

void MasterSummonerEffect::activate(GameState *gameState){
    if(player->getHand().size() == 5){
        throw invalid_argument("Cannot summon any more minions");
    }
    else if(player->getMagic() < 2){
        throw invalid_argument("Not enough magic to use this ability.");
    }
    else{
        player->setMagic(player->getMagic() - 2);
        int numberOfMinions = min(3, int(5 - player->getField().size()));
        for(int x = 0; x < numberOfMinions; x++){
            player->addMinionToField((shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Air Elemental", 0, player, 1, 1))));
        }
    }
}

void MasterSummonerEffect::activate(GameState *gameState, int p, std::string t){
    throw invalid_argument("This is not a targeted ability.");
}

int MasterSummonerEffect::getCost(){
    return 1;
}

MasterSummonerEffect::~MasterSummonerEffect(){}
