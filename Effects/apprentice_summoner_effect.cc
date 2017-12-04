#include <stdexcept>
#include "apprentice_summoner_effect.h"
#include "../base_minion_card.h"

using std::string;
using std::shared_ptr;
using std::make_shared;
using std::invalid_argument;

ApprenticeSummonerEffect::ApprenticeSummonerEffect(Player *player):ActivatedEffect{"Summon a 1/1 air elemental"}, player{player}{}

void ApprenticeSummonerEffect::activate(GameState *gameState){
    if(player->getField().size() == 5){
        throw invalid_argument("Cannot summon any more minions");
    }
    else{
        player->addMinionToField((shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Air Elemental", 0, player, 1, 1))));
    }
}

void ApprenticeSummonerEffect::activate(GameState *gameState, int p, std::string t){
    throw invalid_argument("This is not a targeted ability.");
}

int ApprenticeSummonerEffect::getCost(){
    return 1;
}

ApprenticeSummonerEffect::~ApprenticeSummonerEffect(){}
