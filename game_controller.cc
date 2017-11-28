#include <iostream>
#include "game_controller.h"
#include "subject.h"

GameController::GameController(std::shared_ptr<GameState> gameState):gameState{gameState}{}

void GameController::notify(Subject<std::string> &whoFrom){
    std::cout<<whoFrom.getInfo()<<std::endl;
}

void GameController::startGame(){
    gameState->setRenderMode(RenderMode::GET_NAME);
}
