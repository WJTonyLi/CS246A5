#include "spell_card.h"

using std::string;
using std::shared_ptr;

SpellCard::SpellCard(string name, int cost, Player *player, std::shared_ptr<ActivatedEffect> effect): AbstractCard{name, cost, player}, effect{effect}{}

card_template_t SpellCard::getGraphics() const{
    return display_spell(getName(), getCost(), "Nuthing");
}

void SpellCard::play(GameState *gameState){
    effect->activate(gameState);
}

void SpellCard::play(GameState *gameState, int p, std::string t){}

SpellCard::~SpellCard(){}
