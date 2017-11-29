#include "spell_card.h"

SpellCard::SpellCard(std::string name, int cost, Player& player, std::shared_ptr<ActivatedEffect> effect):effect{effect}, AbstractCard{name, cost, player}{}

SpellCard::~SpellCard(){}
