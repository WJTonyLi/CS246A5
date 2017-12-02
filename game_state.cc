#include <stdexcept>
#include "game_state.h"

using std::string;
using std::shared_ptr;
using std::make_shared;

GameState::GameState(string deckFile1, string deckFile2):p1{make_shared<Player>(deckFile1)}, p2{make_shared<Player>(deckFile2)}, status{CurrentStatus::GET_NAME}, currentTurn{1}{}

shared_ptr<Player> GameState::getPlayer1(){
    return p1;
}

shared_ptr<Player> GameState::getPlayer2(){
    return p2;
}

shared_ptr<Player> GameState::getCurrentPlayer(){
    if(currentTurn == 1){
        return p1;
    }
    else if(currentTurn == 2){
        return p2;
    }
    else{
        throw std::runtime_error("Current player is not 1 or 2.");
    }
}

shared_ptr<Player> GameState::getCurrentOpponent() {
    return (currentTurn == 1) ? p2 : p1;
}

void GameState::setCurrentStatus(CurrentStatus status){
    this->status = status;
}

void GameState::getInfo() const{}

int GameState::getTurn(){
    return currentTurn;
}

void GameState::endTurn(){
    if(currentTurn == 1){
        currentTurn = 2;
        if(status != CurrentStatus::GET_NAME){
            p2->startTurn();
        }
    }
    else if(currentTurn == 2){
        currentTurn = 1;
        if(status != CurrentStatus::GET_NAME){
            p1->startTurn();
        }
    }
}

void GameState::setCurrentPlayerName(std::string newName){
    if(currentTurn == 1){
        p1->setName(newName);
    }
    else if(currentTurn == 2){
        p2->setName(newName);
    }
}

CurrentStatus GameState::getCurrentStatus(){
    return status;
}

void GameState::renderNow(){
    notifyObservers();
}

void GameState::play(int i){
    getCurrentPlayer()->play(this, i);
}

void GameState::play(int i, int p, int t){
    getCurrentPlayer()->play(this, i, p ,t);
}

void GameState::attackEnemy(int i){
    getCurrentPlayer()->attackEnemy(this, i);
}

void GameState::attackEnemy(int i, int j){
    getCurrentPlayer()->attackEnemy(this, i, j);
}

GameState::~GameState(){}
