#include "base_minion_card.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{nullptr}, hasActivated{false}, hasTriggered{false}{}

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense, shared_ptr<ActivatedEffect> activeAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{activeAbility}, triggeredAbility{nullptr}, hasActivated{true}, hasTriggered{false}{}

BaseMinionCard::BaseMinionCard(string name, int cost, Player *player, int attack, int defense, shared_ptr<TriggeredEffect> triggeredAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{triggeredAbility}, hasActivated{false}, hasTriggered{true}{}

void BaseMinionCard::play(GameState *gameState){
    getOwner()->addMinionToField(make_shared<BaseMinionCard>(*this));
}

void BaseMinionCard::play(GameState *gameState, int p, string t){}

void BaseMinionCard::use(GameState *gameState){
    activeAbility->activate(gameState);
}

void BaseMinionCard::use(GameState *gameState, int p, string t){
    activeAbility->activate(gameState, p, t);
}

card_template_t BaseMinionCard::getGraphics() const{
    return display_minion_no_ability(getName(), getCost(), getAttack(), getDefense());
}

BaseMinionCard::~BaseMinionCard(){}
