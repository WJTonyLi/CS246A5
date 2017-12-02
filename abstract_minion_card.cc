#include "abstract_minion_card.h"
#include "player.h"

using std::shared_ptr;

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, Player *player, int attack, int defense):AbstractCard(name, cost, player), attack{attack}, defense{defense}, originalAttack{attack}, originalDefense{defense}{}

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

void AbstractMinionCard::attackEnemy(GameState *gameState) {
    int currentLife = gameState->getCurrentOpponent()->getLife();
    int newLife = currentLife - attack;
    gameState->getCurrentOpponent()->setLife(newLife);
}

void AbstractMinionCard::attackEnemy(AbstractMinionCard& minion) {
    int enemyAttack = minion.getAttack();
    int enemyDefense = minion.getDefense();
    int newDefense = enemyDefense - attack;
    minion.setDefense(newDefense);
    defense -= enemyAttack;
}

AbstractMinionCard::~AbstractMinionCard(){}
