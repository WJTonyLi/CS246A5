#include <stdexcept>
#include "game_state.h"

using std::shared_ptr;

GameState::GameState():p1{},p2{}, status{CurrentStatus::GET_NAME}, currentTurn{1}{}

const Player& GameState::getPlayer1(){
    return p1;
}

const Player& GameState::getPlayer2(){
    return p2;
}

const Player& GameState::getCurrentPlayer(){
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
            p2.startTurn();
        }
    }
    else if(currentTurn == 2){
        currentTurn = 1;
        if(status != CurrentStatus::GET_NAME){
            p1.startTurn();
        }
    }
}

void GameState::setCurrentPlayerName(std::string newName){
    if(currentTurn == 1){
        p1.setName(newName);
    }
    else if(currentTurn == 2){
        p2.setName(newName);
    }
}

CurrentStatus GameState::getCurrentStatus(){
    return status;
}

void GameState::renderNow(){
    notifyObservers();
}

GameState::~GameState(){}
