#include "abstract_card.h"

AbstractCard::AbstractCard(std::string name, int cost, std::shared_ptr<Player> player): name{name}, cost{cost}, owner{player}{}

std::string AbstractCard::getName(){
    return name;
}

int AbstractCard::getCost(){
    return cost;
}

AbstractCard::~AbstractCard(){}
