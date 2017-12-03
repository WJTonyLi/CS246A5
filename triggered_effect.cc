#include "triggered_effect.h"

using std::shared_ptr;
using std::string;

TriggeredEffect::TriggeredEffect(string description):description{description}, owner{nullptr} {}

TriggeredEffect *TriggeredEffect::getThis(){
    return this;
}

void TriggeredEffect::setOwner(shared_ptr<AbstractMinionCard> owner){
    this->owner = owner;
}

shared_ptr<AbstractMinionCard> TriggeredEffect::getOwner(){
    return owner;
}

string TriggeredEffect::getDescription(){
    return description;
}

TriggeredEffect::~TriggeredEffect(){
}
