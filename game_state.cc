#include "game_state.h"

using std::shared_ptr;

GameState::GameState():p1{new Player()},p2{new Player()}{}

shared_ptr<const Player> GameState::getPlayer1(){
    return shared_ptr<const Player>(p1);
}

shared_ptr<const Player> GameState::getPlayer2(){
    return shared_ptr<const Player>(p2);
}

GameState::~GameState(){}
