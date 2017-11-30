#include "spell_card.h"

SpellCard::SpellCard(std::string name, int cost, std::shared_ptr<Player> player, std::shared_ptr<ActivatedEffect> effect): AbstractCard{name, cost, player}, effect{effect}{}

card_template_t SpellCard::getGraphics(){
    return display_spell(getName(), getCost(), "Nuthing");
}

SpellCard::~SpellCard(){}
