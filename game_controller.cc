#include <iostream>
#include <sstream>
#include "game_controller.h"
#include "subject.h"

// debug
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

GameController::GameController(std::shared_ptr<GameState> gameState):gameState{gameState}{}

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
            cout << command << endl;
        } else if (command == "end") {
            cout << command << endl;
        } else if (command == "quit") {
            cout << command << endl;
        } else if (command == "draw") {
            cout << command << endl;
        } else if (command == "discard") {
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
            cout << command << endl;
        } else if (command == "board") {
            gameState->renderNow();
        } else {
            // throw invalidCommand
        }
    }
}

void GameController::startGame(){
    gameState->setCurrentStatus(CurrentStatus::GET_NAME);
    gameState->renderNow();
}
