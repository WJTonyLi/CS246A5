#include "abstract_minion_card.h"

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, Player& player, int attack, int defense): attack{attack}, defense{defense}, AbstractCard(name, cost, player){}

AbstractMinionCard::~AbstractMinionCard(){}

void AbstractMinionCard::attackEnemy(Player& player) {
    int currentLife = player.getLife();
    int newLife = currentLife - attack;
    player.setLife(newLife);
}

void AbstractMinionCard::attackEnemy(AbstractMinionCard& minion) {
}
