#include "abstract_minion_card.h"

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, Player& player, int attack, int defense): attack{attack}, defense{defense}, AbstractCard(name, cost, player){}

AbstractMinionCard::~AbstractMinionCard(){}
