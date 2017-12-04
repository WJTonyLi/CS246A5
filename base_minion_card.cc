#include "base_minion_card.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{nullptr}, hasActivated{false}, hasTriggered{false}{}

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense, shared_ptr<ActivatedEffect> activeAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{activeAbility}, triggeredAbility{nullptr}, hasActivated{true}, hasTriggered{false}{}

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense, shared_ptr<TriggeredEffect> triggeredAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{triggeredAbility}, hasActivated{false}, hasTriggered{true}{}

int BaseMinionCard::getAbilityCost() const {
    return activeAbility->getCost();
}

void BaseMinionCard::play(GameState *gameState){
    shared_ptr<BaseMinionCard> copyOfSelf = make_shared<BaseMinionCard>(*this);
    getOwner()->addMinionToField(copyOfSelf);
    if(hasTriggered){
        this->triggeredAbility->setOwner(copyOfSelf);
        this->triggeredAbility->activate(gameState);
    }
}

void BaseMinionCard::play(GameState *gameState, int p, string t){}

void BaseMinionCard::use(GameState *gameState){
    activeAbility->activate(gameState);
}

void BaseMinionCard::use(GameState *gameState, int p, string t){
    activeAbility->activate(gameState, p, t);
}

card_template_t BaseMinionCard::getGraphics() const{
    if(hasActivated){
        return display_minion_activated_ability(getName(), getCost(), getAttack(), getDefense(), activeAbility->getCost(), activeAbility->getDescription());
    }
    else if(hasTriggered){
        return display_minion_triggered_ability(getName(), getCost(), getAttack(), getDefense(), triggeredAbility->getDescription());
    }
    else{
        return display_minion_no_ability(getName(), getCost(), getAttack(), getDefense());
    }
}

BaseMinionCard::~BaseMinionCard(){}
