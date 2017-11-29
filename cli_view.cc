#include "cli_view.h"

using std::getline;
using std::istream;
using std::string;

CliView::CliView(istream& is): is{is} {}

string CliView::getInfo() const {
    return command;
}

void CliView::readCommands() {
    while (getline(is, command)) {
        notifyObservers();    
    }
}
