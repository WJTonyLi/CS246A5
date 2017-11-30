#include "player.h"
#include "spell_card.h"

using std::string;

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{}

Player::Player(std::string deckFileName):life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{
    //TODO initialize deck base on deckFileName.deck
}

int Player::getLife() const{
    return life;
}

void Player::setLife(int life){
    this->life = life;
}

int Player::getMagic() const{
    return magic;
}

void Player::setMagic(int magic){
    this->magic = magic;
}

string Player::getName() const{
    return name;
}

void Player::setName(string name){
    this->name = name;
}

void Player::drawACard(){
    if(deck.size() > 0){
        hand.emplace_back(deck.back());
        deck.pop_back();
    }
}

void Player::playCard(int index){
    if((index >= 0) && (index < int(hand.size()))){
        hand.erase(hand.begin() + index);
    }
}

void Player::startTurn(){
    magic++;
    drawACard();
}

Player::~Player(){}
