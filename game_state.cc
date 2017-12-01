#include <stdexcept>
#include "game_state.h"
#include <iostream>

using namespace std;
using std::string;
using std::shared_ptr;
using std::make_shared;

GameState::GameState():p1{make_shared<Player>()}, p2{make_shared<Player>()}, status{CurrentStatus::GET_NAME}, currentTurn{1}{}

std::shared_ptr<Player> GameState::getPlayer1(){
    return p1;
}

std::shared_ptr<Player> GameState::getPlayer2(){
    return p2;
}

std::shared_ptr<Player> GameState::getCurrentPlayer(){
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
    cout<<"GAMESTATE PLAY CALLED"<<endl;
    getCurrentPlayer()->play(this, i);
}

void GameState::play(int i, int p, string t){
    getCurrentPlayer()->play(this, i, p ,t);
}

GameState::~GameState(){}
