#include "base_minion_card.h"

BaseMinionCard::BaseMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{nullptr}{}

BaseMinionCard::BaseMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense, std::shared_ptr<ActivatedEffect> activeAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{activeAbility}, triggeredAbility{nullptr}{}

BaseMinionCard::BaseMinionCard(std::string name, int cost, std::shared_ptr<Player> player, int attack, int defense, std::shared_ptr<TriggeredEffect> triggeredAbility):AbstractMinionCard{name, cost, player, attack, defense}, activeAbility{nullptr}, triggeredAbility{triggeredAbility}{}

BaseMinionCard::~BaseMinionCard(){}
