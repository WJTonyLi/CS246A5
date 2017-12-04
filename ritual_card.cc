#include "ritual_card.h"

using std::string;
using std::make_shared;
using std::invalid_argument;

RitualCard::RitualCard(string name, int cost, Player *player, string description, int activationCost, int charges):AbstractCard{name, cost, player}, description{description}, charges{charges}, activationCost{activationCost}{}

card_template_t RitualCard::getGraphics() const{
    return display_ritual(getName(), getCost(), activationCost, description, charges);
}

void RitualCard::play(GameState *gameState, int p, std::string t){
    throw invalid_argument("Ritual cards are not targeted");
}

string RitualCard::getDescription(){
    return description;
}

void RitualCard::conditionMet(){
    if(activationCost <= charges){
        applyEffects();
        charges -= activationCost;
    }
}

card_template_t RitualCard::getGraphics(){
    return display_ritual(getName(), getCost(), activationCost, description, charges);
}

RitualCard::~RitualCard(){}
