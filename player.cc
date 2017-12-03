#include <stdexcept>
#include "player.h"
#include "spell_card.h"
#include "base_minion_card.h"
#include "Effects/blizzard_effect.h"
#include "Effects/apprentice_summoner_effect.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;
using std::string;
using std::ifstream;
using std::exception;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;
using std::invalid_argument;

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    hand.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Earth Elemental", 3, this, 4, 4)));
    hand.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
}

Player::Player(string deckFileName):life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}{
    cout<<deckFileName<<endl;
    ifstream deckFile;
    deckFile.open(deckFileName);
    string cardName;
    if(deckFile.fail()){
        throw invalid_argument("Could not open deckfile " + deckFileName + ".");
    }
    else{
        while (std::getline(deckFile, cardName)){
            if(cardName == "Blizzard"){
                deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
            }
            else if(cardName == "Earth Elemental"){
                deck.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Earth Elemental", 3, this, 4, 4)));
            }
            else if(cardName == "Air Elemental"){
                deck.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Air Elemental", 0, this, 1, 1)));
            }
            else if(cardName == "Apprentice Summoner"){
                deck.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Apprentice Summoner", 1, this, 1, 1, make_shared<ApprenticeSummonerEffect>(this))));
            }
        }
    }
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

std::shared_ptr<AbstractMinionCard> Player::getFieldMinion(int i) const {
    if (int(field.size()) < i || i < 1) {
        throw out_of_range("No card at that index.");
    }
    return field.at(i - 1);
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
    for (auto &n: field) {
        n->incrementActions();
    }
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

void Player::shuffle(){
    srand (time(NULL));
    random_shuffle(deck.begin(), deck.end());
}

void Player::play(GameState *gameState, int i){
    if((int(hand.size()) >= i && i >= 1) && (magic >= hand.at(i-1)->getCost())){
        shared_ptr<AbstractCard> cardToPlay = hand.at(i-1);
        hand.erase(hand.begin() + i-1);
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
    else if(int(hand.size()) < i || i < 1){
        throw out_of_range("No card at that index.");
    }
    else{
        throw invalid_argument("Not enough magic to play that card.");
    }
}

void Player::play(GameState *gameState, int i, int p, string t){}

void Player::use(GameState *gameState, int i){
    if(int(field.size()) >= i && i >= 1){
        try{
            field.at(i - 1)->use(gameState);
        }
        catch(exception e){
            throw e;
        }
    }
    else{
        throw out_of_range("No card at that index.");
    }
}

void Player::use(GameState *gameState, int i, int p, string t){}

void Player::addMinionToField(shared_ptr<AbstractMinionCard> minion){
    field.emplace_back(minion);
}

void Player::attackEnemy(GameState *gameState, int i){
    // TODO implement minion action limit and death
    if(int(field.size()) >= i && i >= 1){
        shared_ptr<AbstractMinionCard> minionToAttack = field.at(i-1);
        if (minionToAttack->getActions() <= 0) {
            throw invalid_argument("Not enough actions to attack.");
        }
        minionToAttack->attackEnemy(gameState);
        minionToAttack->useAction();
    } else {
        throw out_of_range("No card at that index.");
    }
}

void Player::attackEnemy(GameState *gameState, int i, int j) {
    // TODO implement minion action limit and death
    if (int(field.size()) >= i && i >= 1){
        shared_ptr<AbstractMinionCard> minionToAttack = field.at(i - 1);
        minionToAttack->attackEnemy(gameState, j);
        shared_ptr<Player> opponent = gameState->getCurrentOpponent();
        if(field.at(i - 1)->isDead()){
            this->moveToGraveyard(i - 1);
        }
        if(opponent->field.at(j - 1)->isDead()){
            opponent->moveToGraveyard(j - 1);
        }
    }
    else if(int(field.size()) < i || i < 1){
        throw out_of_range("No card at that index.");
    }
    else{
        throw invalid_argument("Not enough actions to attack.");
    }
}

void Player::moveToGraveyard(int i){
    //TODO remove enchatments before moving to graveyard
    if(i >= 0 && i < int(field.size())){
        graveyard.push_back(field.at(i));
        field.erase(field.begin() + i);
    }
    else{
        throw out_of_range("No card at that index.");
    }
}

Player::~Player(){}
