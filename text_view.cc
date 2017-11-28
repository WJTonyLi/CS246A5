#include "text_view.h"

using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::istream;
using std::ostream;
using std::shared_ptr;

TextView::TextView(std::istream& is, std::ostream& os, std::shared_ptr<GameState> gameState):is{is}, os{os}, gameState{gameState}{
}

std::string TextView::getInfo() const{
    string command;
    getline(is, command);
    return command;
}

void TextView::notify(Subject<void> &whoFrom){
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        cout<<"Please enter Player "<<gameState->getTurn()<<" name: ";
        notifyObservers();
    }
}

TextView::~TextView(){};
