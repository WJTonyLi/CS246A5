#include "text_view.h"

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

void TextView::test(){
    notifyObservers();
}

TextView::~TextView(){};
