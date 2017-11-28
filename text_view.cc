#include "text_view.h"

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
    if(gameState->getRenderMode() == RenderMode::GET_NAME){
        string name1;
        os<<"Enter P1 name:"<<endl;
        is>>name1;
        string name2;
        os<<"Enter P2 name:"<<endl;
        is>>name2;
    }
}

TextView::~TextView(){};
