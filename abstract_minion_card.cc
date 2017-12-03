#include "abstract_minion_card.h"
#include "player.h"

AbstractMinionCard::AbstractMinionCard(std::string name, int cost, Player *player, int attack, int defense):AbstractCard(name, cost, player), attack{attack}, defense{defense}, actions{0} {}

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

int AbstractMinionCard::getActions() const {
    return actions;
}

void AbstractMinionCard::incrementActions() {
    this->actions += 1;
}

void AbstractMinionCard::useAction() {
    this->actions -= 1;
}

void AbstractMinionCard::attackEnemy(GameState *gameState) {
    int currentLife = gameState->getCurrentOpponent()->getLife();
    int newLife = currentLife - attack;
    gameState->getCurrentOpponent()->setLife(newLife);
}

void AbstractMinionCard::attackEnemy(GameState *gameState, int j) {
    std::shared_ptr<AbstractMinionCard> enemy = gameState->getCurrentOpponent()->getFieldMinion(j);
    int enemyAttack = enemy->getAttack();
    int enemyDefense = enemy->getDefense();
    int newDefense = enemyDefense - attack;
    enemy->setDefense(newDefense);
    defense -= enemyAttack;
}

bool AbstractMinionCard::isDead(){
    return getDefense() <= 0;
}

AbstractMinionCard::~AbstractMinionCard(){}
