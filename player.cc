#include "player.h"

using std::string;

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{}

int Player::getLife() const{
    return life;
}

int Player::setLife(int life){
    this->life = life;
}

int Player::getMagic() const{
    return magic;
}

int Player::setMagic(int magic){
    this->magic = magic;
}

string Player::getName() const{
    return name;
}

void Player::setName(string name){
    this->name = name;
}

Player::~Player(){}
