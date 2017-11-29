#include <fstream>
#include <iostream>
#include <memory>
#include "cli_view.h"
#include "game_state.h"
#include "game_controller.h"
#include "text_view.h"

using namespace std;

int main(int argc, char *argv[])
{
    string deckFile1 = "default.deck";
    string deckFile2 = "default.deck";
    string initFile;
    bool testMode = false;
    bool graphics = false;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == "-deck1") {
            if (i + 1 < argc) {
                deckFile1 = argv[i++];
            } else {
                cerr << "-deck1 requires one argument" << endl;
            }
        } else if (argv[i] == "-deck2") {
            if (i + 1 < argc) {
                deckFile2 = argv[i++];
            } else {
                cerr << "-deck2 requires one argument" << endl;
            }
        } else if (argv[i] == "-init") {
            if (i + 1 < argc) {
                string initFile = argv[i++];
            } else {
                cerr << "-init requires one argument" << endl;
            }
        } else if (argv[i] == "-testing") {
            testMode = true;
        } else if (argv[i] == "-graphics") {
            graphics = true;
        } else {
            cerr << "Invalid argument" << endl;
        }
    }

    //this is just code to test my stuff, ignore this for now
    shared_ptr<GameState> gs(new GameState());
    shared_ptr<TextView> tv(new TextView(cout, gs));
    shared_ptr<GameController> gc(new GameController(gs));
    tv->attach(gc);
    gs->attach(tv);
    gc->startGame();

    // Handle -init option
    if (initFile == "") {
        if (ifstream file{initFile}) {
            CliView initInput{file};
            initInput.readCommands();
        } else {
        cerr << "File for -init not found" << endl;
        }
    }

    // Get user input
    CliView userInput{cin};
    userInput.readCommands();

    return 0;
}
