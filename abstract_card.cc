#include "abstract_card.h"

AbstractCard::AbstractCard(std::string name, int cost, Player& player): name{name}, cost{cost}, owner{player}{}

AbstractCard::~AbstractCard(){}
