#include <exception>
#include <iostream>
#include <sstream>
#include "game_controller.h"
#include "shared_ptr_subject.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::istringstream;

GameController::GameController(std::shared_ptr<GameState> gameState, bool testMode, bool graphics):
    gameState{gameState}, testMode{testMode}, graphics{graphics} {}

void GameController::notify(SharedPtrSubject<std::string> &whoFrom){
    istringstream iss(whoFrom.getInfo());
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        gameState->setCurrentPlayerName(iss.str());
        if(gameState->getTurn() == 2){
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
            if(!testMode){
                gameState->getPlayer1()->shuffle();
                gameState->getPlayer2()->shuffle();
            }
            for(int x = 0; x < 5; x++){
                gameState->getPlayer1()->drawACard();
            }
            for(int x = 0; x < 5; x++){
                gameState->getPlayer2()->drawACard();
            }
            gameState->endTurn();
            gameState->renderNow();
        }
        else{
            gameState->endTurn();
            gameState->renderNow();
        }
    }
    else{
        string command;
        iss >> command;
        if(command == "help"){
            gameState->setCurrentStatus(CurrentStatus::HELP_MESSAGE);
            gameState->renderNow();
        }
        else if(command == "end"){
            gameState->endTurn();
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
            gameState->renderNow();
        }
        else if(command == "quit"){
            gameState->setCurrentStatus(CurrentStatus::GAME_END);
        }
        else if(command == "draw" && testMode){
            gameState->getCurrentPlayer()->drawACard();
        }
        else if (command == "discard" && testMode){
            int i;
            if (iss >> i){
                try {
                    gameState->getCurrentPlayer()->discardCard(i);
                }
                catch(std::out_of_range& e) {
                    cerr << e.what() << endl;
                }
            }
            else{
                cerr << "Invalid Command." << endl;
            }
        }
        else if (command == "attack"){
            int i;
            if(iss >> i){
                int j;
                if(iss >> j){
                    try{
                        gameState->attackEnemy(i, j);
                    }
                    catch(std::out_of_range& e){
                        cerr << e.what() << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }
                else{
                    try{
                        gameState->attackEnemy(i);
                        if (gameState->getCurrentOpponent()->getLife() <= 0) {
                            gameState->setCurrentStatus(CurrentStatus::GAME_WON);
                            gameState->renderNow();
                            gameState->setCurrentStatus(CurrentStatus::GAME_END);
                        }
                    }
                    catch(std::out_of_range& e){
                        cerr << e.what() << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }
            }
            else{
                cerr << "Invalid Command." << endl;
            }
        }
        else if(command == "play"){
            int i;
            if(iss >> i){
                int p;
                string t;
                if (iss >> p && iss >> t){
                    try{
                        if (!testMode) {
                            if(gameState->getCurrentPlayer()->getMagic() < gameState->getCurrentPlayer()->getHandCost(i)){
                                throw std::invalid_argument("Not enough magic to play that card.");
                            }
                        }
                        gameState->play(i, p, t);
                    }
                    catch(std::out_of_range){
                        cerr << "No card at that index." << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }else{
                    try{
                        if (!testMode) {
                            if(gameState->getCurrentPlayer()->getMagic() < gameState->getCurrentPlayer()->getHandCost(i)){
                                throw std::invalid_argument("Not enough magic to play that card.");
                            }
                        }
                        gameState->play(i);
                    }
                    catch(std::out_of_range){
                        cerr << "No card at that index." << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }
            }
            else{
                cerr << "Invalid Command." << endl;
            }
        }
        else if(command == "use"){
            int i;
            if (iss >> i){
                int p;
                string t;
                if(iss >> p && iss>>t){
                    try{
                        gameState->use(i, p, t);
                    }
                    catch(std::out_of_range& e){
                        cerr << e.what() << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }
                else{
                    try{
                        if (!testMode) {
                            if(gameState->getCurrentPlayer()->getMagic() < gameState->getCurrentPlayer()->getFieldMinionCost(i)){
                                throw std::invalid_argument("Not enough magic to play that card.");
                            }
                        }
                        gameState->use(i);
                    }
                    catch(std::out_of_range){
                        cerr << "No card at that index." << endl;
                    }
                    catch(std::invalid_argument& e){
                        cerr << e.what() << endl;
                    }
                }
            }
            else{
                cerr << "Invalid Command." << endl;
            }
        }
        else if(command == "hand"){
            gameState->setCurrentStatus(CurrentStatus::SHOW_HAND);
            gameState->renderNow();
        }
        else if(command == "board"){
            gameState->setCurrentStatus(CurrentStatus::SHOW_BOARD);
            gameState->renderNow();
        }
        else{
            cerr << "Invalid Command." << endl;
        }
    }
}

void GameController::startGame(){
    gameState->setCurrentStatus(CurrentStatus::GET_NAME);
    gameState->renderNow();
}
