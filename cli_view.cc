#include "cli_view.h"

using std::getline;
using std::istream;
using std::string;

CliView::CliView(istream& is): is{is}, done{false} {}

bool CliView::isDone() const {
    return done;
}

string CliView::getInfo() const {
    return command;
}

void CliView::readCommands() {
    if (getline(is, command)) {
        notifyObservers();    
    } else {
        done = true;
    }
}
