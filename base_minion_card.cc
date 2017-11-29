#include "base_minion_card.h"

BaseMinionCard::BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense):activeAbility{nullptr}, triggeredAbility{nullptr}, AbstractMinionCard{name, cost, player, attack, defense}{}

BaseMinionCard::BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense, std::shared_ptr<ActivatedEffect> activeAbility):activeAbility{activeAbility}, triggeredAbility{nullptr}, AbstractMinionCard{name, cost, player, attack, defense}{}

BaseMinionCard::BaseMinionCard(std::string name, int cost, Player& player, int attack, int defense, std::shared_ptr<TriggeredEffect> triggeredAbility):activeAbility{nullptr}, triggeredAbility{triggeredAbility}, AbstractMinionCard{name, cost, player, attack, defense}{}

BaseMinionCard::~BaseMinionCard(){}
