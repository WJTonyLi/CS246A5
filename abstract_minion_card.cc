#include "abstract_minion_card.h"

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense): AbstractCard(name, cost, player), attack{attack}, defense{defense}{}

AbstractMinionCard::~AbstractMinionCard(){}

void AbstractMinionCard::attackEnemy(Player& player) {
    int currentLife = player.getLife();
    int newLife = currentLife - attack;
    player.setLife(newLife);
}

void AbstractMinionCard::attackEnemy(AbstractMinionCard& minion) {
}
