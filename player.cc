#include <stdexcept>
#include "player.h"
#include "spell_card.h"
#include "base_minion_card.h"
#include "Effects/blizzard_effect.h"
#include "Effects/bone_golem_effect.h"
#include "Effects/master_summoner_effect.h"
#include "Effects/novice_pyromancer_effect.h"
#include "Effects/apprentice_summoner_effect.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

using std::string;
using std::ifstream;
using std::exception;
using std::shared_ptr;
using std::make_shared;
using std::out_of_range;
using std::invalid_argument;

Event::Event(EventType eventType):eventType{eventType}{}

Event::Event(EventType eventType, std::shared_ptr<AbstractMinionCard> minion):eventType{eventType}, minion{minion}{}

EventType Event::getEventType(){
    return eventType;
}

std::shared_ptr<AbstractMinionCard> Event::getMinion(){
    return minion;
}

Player::Player():life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}, lastEvent{EventType::BEGINNING_TURN}{
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    deck.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
    hand.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Earth Elemental", 3, this, 4, 4)));
    hand.emplace_back(shared_ptr<SpellCard>(make_shared<SpellCard>("Blizzard", 3, this, shared_ptr<ActivatedEffect>(make_shared<BlizzardEffect>()))));
}

Player::Player(string deckFileName):life{20}, magic{3}, name{""}, deck{}, hand{}, field{}, graveyard{}, lastEvent{EventType::BEGINNING_TURN}{
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
            else if(cardName == "Master Summoner"){
                deck.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Master Summoner", 3, this, 2, 3, make_shared<MasterSummonerEffect>(this))));
            }
            else if(cardName == "Novice Pyromancer"){
                deck.emplace_back(shared_ptr<BaseMinionCard>(make_shared<BaseMinionCard>("Novice Pyromancer", 1, this, 0, 1, make_shared<NovicePyromancerEffect>(this))));
            }
            else if(cardName == "Bone Golem"){
                deck.emplace_back(make_shared<BaseMinionCard>("Bone Golem", 2, this, 1, 3, make_shared<BoneGolemEffect>()));
            }
        }
    }
}

Event Player::getInfo() const{
    return lastEvent;
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
    try {
        return field.at(i-1);
    }
    catch (out_of_range) {
        throw out_of_range("No card at that index.");
    }
}

int Player::getHandCost(int i) const {
    try {
        return hand.at(i-1)->getCost();
    }
    catch (out_of_range) {
        throw out_of_range("No card at that index.");
    }
}


void Player::drawACard(){
    if(deck.size() > 0 && hand.size() < 5){
        hand.emplace_back(deck.back());
        deck.pop_back();
    }
}

void Player::discardCard(int i) {
    try {
        hand.erase(hand.begin() + i - 1);
    }
    catch (out_of_range) {
        throw out_of_range("No card at that index.");
    }
}

void Player::startTurn(){
    magic++;
    drawACard();
    for (auto &n: field) {
        if (n->getActions() < 1) n->incrementActions();
    }
}

void Player::endTurn(){
    lastEvent = Event{EventType::ENDING_TURN};
    notifyObservers();
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
    random_shuffle(deck.begin(), deck.end());
}

void Player::play(GameState *gameState, int i){
    shared_ptr<AbstractCard> cardToPlay = hand.at(i-1);
    hand.erase(hand.begin() + i-1);
    magic -= cardToPlay->getCost();
    try{
        cardToPlay->play(gameState);
    }
    catch(exception &e){
        hand.insert(hand.begin() + i, cardToPlay);
        magic += cardToPlay->getCost();
        throw e;
    }
}

void Player::play(GameState *gameState, int i, int p, string t){}

void Player::use(GameState *gameState, int i){
    try{
        shared_ptr<AbstractMinionCard> minionToCast = field.at(i-1);
        if (minionToCast->getActions() <= 0) {
            throw invalid_argument("Not enough actions to attack.");
        }
        minionToCast->use(gameState);
        minionToCast->useAction();
    }catch(out_of_range){
        throw out_of_range("No card at that index.");
    }
}

void Player::use(GameState *gameState, int i, int p, string t){
    try {
        shared_ptr<AbstractMinionCard> minionToCast = field.at(i-1);
        if (minionToCast->getActions() <= 0) {
            throw invalid_argument("Not enough actions to attack.");
        }
        minionToCast->use(gameState, p, t);
        minionToCast->useAction();
    }
    catch (out_of_range) {
        throw out_of_range("No card at that index.");
    }
}

void Player::addMinionToField(shared_ptr<AbstractMinionCard> minion){
    field.emplace_back(minion);
    lastEvent = {EventType::MINION_ENTERED, field.back()};
    notifyObservers();
}

void Player::attackEnemy(GameState *gameState, int i){
    try{
        shared_ptr<AbstractMinionCard> minionToAttack = field.at(i-1);
        if (minionToAttack->getActions() <= 0) {
            throw invalid_argument("Not enough actions to attack.");
        }
        minionToAttack->attackEnemy(gameState);
        minionToAttack->useAction();
    }
    catch(out_of_range){
        throw out_of_range("No card at that index.");
    }
}

void Player::attackEnemy(GameState *gameState, int i, int j) {
    try{
        shared_ptr<AbstractMinionCard> minionToAttack = field.at(i - 1);
        if(minionToAttack->getActions() <= 0){
            throw invalid_argument("Not enough actions to attack.");
        }
        minionToAttack->attackEnemy(gameState, j);
        minionToAttack->useAction();
        shared_ptr<Player> opponent = gameState->getCurrentOpponent();
        if(field.at(i - 1)->isDead()){
            this->moveToGraveyard(i - 1);
        }
        if(opponent->field.at(j - 1)->isDead()){
            opponent->moveToGraveyard(j - 1);
        }
    }
    catch(out_of_range){
        throw out_of_range("No card at that index.");
    }
}

void Player::moveToGraveyard(int i){
    //TODO remove enchatments before moving to graveyard
    try{
        graveyard.push_back(field.at(i));
        field.erase(field.begin() + i);
        lastEvent = {EventType::MINION_LEFT, graveyard.back()};
        notifyObservers();
    }
    catch(out_of_range){
        throw out_of_range("No card at that index.");
    }
}

Player::~Player(){}
