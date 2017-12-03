#include "triggered_effect.h"

using std::shared_ptr;

TriggeredEffect::TriggeredEffect():owner{nullptr}{}

TriggeredEffect *TriggeredEffect::getThis(){
    return this;
}

void TriggeredEffect::setOwner(std::shared_ptr<AbstractMinionCard> owner){
    this->owner = owner;
}

shared_ptr<AbstractMinionCard> TriggeredEffect::getOwner(){
    return owner;
}

TriggeredEffect::~TriggeredEffect(){
}
