#include <iostream>
#include "game_controller.h"
#include "subject.h"

GameController::GameController(std::shared_ptr<GameState> gameState):gameState{gameState}{}

void GameController::notify(Subject<std::string> &whoFrom){
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        gameState->setCurrentPlayerName(whoFrom.getInfo());
        if(gameState->getTurn() == 2){
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
        }
        gameState->endTurn();
    }
    gameState->renderNow();
}

void GameController::startGame(){
    gameState->setCurrentStatus(CurrentStatus::GET_NAME);
    gameState->renderNow();
}
