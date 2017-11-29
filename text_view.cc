#include <vector>
#include "text_view.h"
#include "ascii_graphics.h"

using std::endl;
using std::string;
using std::vector;
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

static void displayTopBorder(ostream &os){
    os<<EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for(int x = 0; x < 165; x++){
        os<<EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    os<<EXTERNAL_BORDER_CHAR_TOP_RIGHT<<endl;
}

static void displayBottomBorder(ostream &os){
    os<<EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for(int x = 0; x < 165; x++){
        os<<EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    os<<EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT<<endl;
}

static void displayCards(vector<card_template_t> cards, ostream &os){
    for(int x = 0; x < int(cards.at(0).size()); x++){
        os<<EXTERNAL_BORDER_CHAR_UP_DOWN;
        for(int y = 0; y < int(cards.size()); y++){
            os<<cards.at(y).at(x);
        }
        os<<EXTERNAL_BORDER_CHAR_UP_DOWN<<endl;
    }
}

void TextView::notify(Subject<void> &whoFrom){
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        os<<"Please enter Player "<<gameState->getTurn()<<" name: ";
        notifyObservers();
    }
    else if(gameState->getCurrentStatus() == CurrentStatus::SHOW_BOARD){
        card_template_t card;
        vector<card_template_t> p1Display;
        vector<card_template_t> p1Minions;
        vector<card_template_t> p2Minions;
        vector<card_template_t> p2Display;
        for(int x = 0; x < 5; x++){
            p1Minions.emplace_back(display_minion_no_ability("Placeholder", 1, 1, 1));
            p2Minions.emplace_back(display_minion_no_ability("Placeholder", 1, 1, 1));
        }
        p1Display.emplace_back(CARD_TEMPLATE_BORDER);
        p1Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p1Display.emplace_back(display_player_card(1, gameState->getPlayer1().getName(), gameState->getPlayer1().getLife(), gameState->getPlayer1().getMagic()));
        p1Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p1Display.emplace_back(display_ritual("Placeholder", 1, 1, "Does nothing", 1));
        p2Display.emplace_back(display_ritual("Placeholder", 1, 1, "Does nothing", 1));
        p2Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p2Display.emplace_back(display_player_card(2, gameState->getPlayer2().getName(), gameState->getPlayer2().getLife(), gameState->getPlayer2().getMagic()));
        p2Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p2Display.emplace_back(CARD_TEMPLATE_BORDER);
        displayTopBorder(os);
        displayCards(p1Display, os);
        displayCards(p1Minions, os);
        for(int x = 0; x < int(CENTRE_GRAPHIC.size()); x++){
            os<<CENTRE_GRAPHIC.at(x)<<endl;
        }
        displayCards(p2Minions, os);
        displayCards(p2Display, os);
        displayBottomBorder(os);
    }
}

TextView::~TextView(){};
