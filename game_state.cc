#include "game_state.h"

using std::shared_ptr;

GameState::GameState():p1{new Player()},p2{new Player()}, status{CurrentStatus::GET_NAME}, currentTurn{1}{}

shared_ptr<const Player> GameState::getPlayer1(){
    return shared_ptr<const Player>(p1);
}

shared_ptr<const Player> GameState::getPlayer2(){
    return shared_ptr<const Player>(p2);
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
    }
    else if(currentTurn == 2){
        currentTurn = 1;
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

GameState::~GameState(){}
