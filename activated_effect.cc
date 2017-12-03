#include "activated_effect.h"

using std::string;

ActivatedEffect::ActivatedEffect(std::string description):description{description}{}

string ActivatedEffect::getDescription(){
    return description;
}

ActivatedEffect::~ActivatedEffect() = default;
