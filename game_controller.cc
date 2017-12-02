#include <exception>
#include <iostream>
#include <sstream>
#include "game_controller.h"
#include "subject.h"

// debug
using std::cout;
using std::cerr;
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
            gameState->endTurn();
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
        } else {
            gameState->endTurn();
            gameState->renderNow();
        }
    } else {
        string command;
        iss >> command;
        if (command == "help") {
            gameState->setCurrentStatus(CurrentStatus::HELP_MESSAGE);
            gameState->renderNow();
        } else if (command == "end") {
            gameState->endTurn();
        } else if (command == "quit") {
            cout << command << endl;
        } else if (command == "draw" && testMode) {
            gameState->getCurrentPlayer()->drawACard();
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
                    try {
                        gameState->attackEnemy(i, j);
                    }
                    catch (std::out_of_range& e) {
                        cerr << e.what() << endl;
                    }
                    catch (std::invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                } else {
                    try {
                        gameState->attackEnemy(i);
                    }
                    catch (std::out_of_range& e) {
                        cerr << e.what() << endl;
                    }
                    catch (std::invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                }
            } else {
                // throw invalidCommand
            }
        } else if (command == "play") {
            int i;
            if (iss >> i) {
                int p;
                int t;
                if (iss >> p && iss >> t) {
                    try {
                        gameState->play(i, p, t);
                    }
                    catch (std::out_of_range& e) {
                        cerr << e.what() << endl;
                    }
                    catch (std::invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
                } else {
                    try {
                        gameState->play(i);
                    }
                    catch (std::out_of_range& e) {
                        cerr << e.what() << endl;
                    }
                    catch (std::invalid_argument& e) {
                        cerr << e.what() << endl;
                    }
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
            cerr << "Invalid Command (this is not an exception yet)" << endl;
        }
    }
}

void GameController::startGame(){
    gameState->setCurrentStatus(CurrentStatus::GET_NAME);
    gameState->renderNow();
}
