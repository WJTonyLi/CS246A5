#include <stdexcept>
#include "spell_card.h"

#include <iostream>

using namespace std;

using std::string;
using std::exception;
using std::shared_ptr;

SpellCard::SpellCard(string name, int cost, Player *player, std::shared_ptr<ActivatedEffect> effect): AbstractCard{name, cost, player}, effect{effect}{}

card_template_t SpellCard::getGraphics() const{
    return display_spell(getName(), getCost(), effect->getDescription());
}

void SpellCard::play(GameState *gameState){
    try{
        effect->activate(gameState);
    }
    catch(exception &e){
        throw e;
    }
}

void SpellCard::play(GameState *gameState, int p, string t){
    try{
        effect->activate(gameState, p, t);
    }
    catch(exception &e){
        throw e;
    }
}

SpellCard::~SpellCard(){}
