#include "abstract_card.h"

AbstractCard::AbstractCard(std::string name, int cost, Player *player): name{name}, cost{cost}, owner{player}{}

std::string AbstractCard::getName() const{
    return name;
}

int AbstractCard::getCost() const{
    return cost;
}

Player *AbstractCard::getOwner(){
    return owner;
}

AbstractCard::~AbstractCard(){}
