#include "player.h"

using std::string;

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{}

string Player::getName() const{
    return name;
}

void Player::setName(string name){
    this->name = name;
}

Player::~Player(){}
