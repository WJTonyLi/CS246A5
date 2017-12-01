#include <stdexcept>
#include "player.h"
#include "spell_card.h"
#include "base_minion_card.h"
#include "Effects/blizzard_effect.h"
#include <iostream>


using namespace std;
using std::string;
using std::shared_ptr;
using std::invalid_argument;
using std::exception;

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    hand.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Earth Elemental", 3, this, 4, 4)));
    hand.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
}

Player::Player(string deckFileName):life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{
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
    if(deck.size() > 0 && hand.size() < 5){
        hand.emplace_back(deck.back());
        deck.pop_back();
    }
}

void Player::startTurn(){
    magic++;
    drawACard();
}

const std::vector<std::shared_ptr<AbstractCard>> Player::getDeck(){
    return deck;
}

const std::vector<std::shared_ptr<AbstractCard>> Player::getHand(){
    return hand;
}

const std::vector<std::shared_ptr<AbstractMinionCard>> Player::getField(){
    return field;
}

void Player::play(GameState *gameState, int i){
    if(int((hand.size()) > i) && (magic >= hand.at(i)->getCost())){
        shared_ptr<AbstractCard> cardToPlay = hand.at(i);
        hand.erase(hand.begin() + i);
        magic -= cardToPlay->getCost();
        try{
            cardToPlay->play(gameState);
        }
        catch(exception e){
            hand.insert(hand.begin() + i, cardToPlay);
            magic += cardToPlay->getCost();
            throw e;
        }
    }
    else if(magic < hand.at(i)->getCost()){
        throw invalid_argument("Not enough magic to play that card.");
    }
    else{
        throw invalid_argument("No such card with that index.");
    }
}

void Player::addMinionToField(shared_ptr<AbstractMinionCard> minion){
    field.emplace_back(minion);
}

void Player::play(GameState *gameState, int i, int p, string t){}

Player::~Player(){}
