#include <iostream>
#include <sstream>
#include "game_controller.h"
#include "subject.h"

// debug
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

GameController::GameController(std::shared_ptr<GameState> gameState, bool testMode, bool graphics):
    gameState{gameState}, testMode{testMode}, graphics{graphics} {}

void GameController::notify(Subject<std::string> &whoFrom){
    istringstream iss(whoFrom.getInfo());
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        gameState->setCurrentPlayerName(iss.str());
        if(gameState->getTurn() == 2){
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
        }
        gameState->endTurn();
        gameState->renderNow();
    } else {
        string command;
        iss >> command;
        if (command == "help") {
            gameState->setCurrentStatus(CurrentStatus::HELP_MESSAGE);
            gameState->renderNow();
        } else if (command == "end") {
            gameState->endTurn();
            gameState->renderNow();
        } else if (command == "quit") {
            cout << command << endl;
        } else if (command == "draw" && testMode) {
            cout << command << endl;
        } else if (command == "discard" && testMode) {
            int i;
            if (iss >> i) {
                cout << command << " " << i << endl;
            } else {
                // throw invalidCommand
            }
        } else if (command == "attack") {
            int i;
            if (iss >> i) {
                int j;
                if (iss >> j) {
                    cout << command << " " << i << " " << j <<  endl;
                } else {
                    cout << command << " " << i << endl;
                }
            } else {
                // throw invalidCommand
            }
        } else if (command == "play") {
            int i;
            if (iss >> i) {
                int p, t;
                if (iss >> p && iss >> t) {
                    cout << command << " " << i << " " << p << " " << t << endl;
                } else {
                    cout << command << " " << i << endl;
                }
            } else {
                // throw invalidCommand
            }
        } else if (command == "use") {
            int i;
            if (iss >> i) {
                int j;
                if (iss >> j) {
                    cout << command << " " << i << " " << j <<  endl;
                } else {
                    cout << command << " " << i << endl;
                }
            } else {
                // throw invalidCommand
            }
        } else if (command == "hand") {
            gameState->setCurrentStatus(CurrentStatus::SHOW_HAND);
            gameState->renderNow();
        } else if (command == "board") {
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
            gameState->renderNow();
        } else {
            // throw invalidCommand
            cout << "Invalid Command (this is not an exception yet)" << endl;
        }
    }
}

void GameController::startGame(){
    gameState->setCurrentStatus(CurrentStatus::GET_NAME);
    gameState->renderNow();
}
