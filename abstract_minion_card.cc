#include "abstract_minion_card.h"

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense): AbstractCard(name, cost, player), attack{attack}, defense{defense}{}

AbstractMinionCard::~AbstractMinionCard(){}

int AbstractMinionCard::getAttack() const {
    return attack;
}

void AbstractMinionCard::setAttack(int value) {
    this->attack = value;
}

int AbstractMinionCard::getDefense() const {
    return defense;
}

void AbstractMinionCard::setDefense(int value) {
    this->defense = value;
}

void AbstractMinionCard::attackEnemy(Player& player) {
    int currentLife = player.getLife();
    int newLife = currentLife - attack;
    player.setLife(newLife);
}

void AbstractMinionCard::attackEnemy(AbstractMinionCard& minion) {
    int enemyAttack = minion.getAttack();
    int enemyDefense = minion.getDefense();
    int newDefense = enemyDefense - attack;
    minion.setDefense(newDefense);
    defense -= enemyAttack;
}
