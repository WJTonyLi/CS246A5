#include <vector>
#include "text_view.h"
#include "abstract_card.h"
#include "ascii_graphics.h"
#include "abstract_minion_card.h"

using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::ostream;
using std::shared_ptr;

TextView::TextView(std::ostream& os, std::shared_ptr<GameState> gameState):
    os{os}, gameState{gameState}{
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

static void displayCards(vector<card_template_t> cards, ostream &os, bool drawSideBorders){
    if(cards.size() > 0){
        for(int x = 0; x < int(cards.at(0).size()); x++){
            if(drawSideBorders){
                os<<EXTERNAL_BORDER_CHAR_UP_DOWN;
            }
            for(int y = 0; y < int(cards.size()); y++){
                os<<cards.at(y).at(x);
            }
            if(drawSideBorders){
                os<<EXTERNAL_BORDER_CHAR_UP_DOWN<<endl;
            }
        }
    }
}

void TextView::notify(Subject<void> &whoFrom){
    if(gameState->getCurrentStatus() == CurrentStatus::GET_NAME){
        os<<"Please enter Player "<<gameState->getTurn()<<" name: " << endl;
    } else if (gameState->getCurrentStatus() == CurrentStatus::HELP_MESSAGE) {
        os << "Commands: help -- Display this message." << endl;
        os << "          end  -- End the current player's turn." << endl;
        os << "          quit -- End the game." << endl;
        os << "          attack minion other-minion -- Orders minion to attack other-minion." << endl;
        os << "          attack minion -- Orders minion to attack the opponent." << endl;
        os << "          play card [target-player target-card] -- Play card, optionally targetting target-card owned by target-player." << endl;
        os << "          use minion [target-player target-card] -- Use minion's special ability, optionally targeting target-card owned by target player." << endl;
        os << "          inspect minion -- View a minion's card and all enchantments on that minion." << endl;
        os << "          hand -- Describe all cards in your hand." << endl;
        os << "          board -- Describe all cards in your board." << endl;
    } else if(gameState->getCurrentStatus() == CurrentStatus::SHOW_BOARD){
        card_template_t card;
        vector<card_template_t> p1Display;
        vector<card_template_t> p1Minions;
        vector<card_template_t> p2Minions;
        vector<card_template_t> p2Display;
        for(int x = 0; x < 5; x++){
            if(x < int(gameState->getPlayer1()->getField().size())){
                p1Minions.emplace_back(gameState->getPlayer1()->getField().at(x)->getGraphics());
            }
            else{
                p1Minions.emplace_back(CARD_TEMPLATE_BORDER);
            }
            if(x < int(gameState->getPlayer2()->getField().size())){
                p2Minions.emplace_back(gameState->getPlayer2()->getField().at(x)->getGraphics());
            }
            else{
                p2Minions.emplace_back(CARD_TEMPLATE_BORDER);
            }
        }
        p1Display.emplace_back(CARD_TEMPLATE_BORDER);
        p1Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p1Display.emplace_back(display_player_card(1, gameState->getPlayer1()->getName(), gameState->getPlayer1()->getLife(), gameState->getPlayer1()->getMagic()));
        p1Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p1Display.emplace_back(display_ritual("Placeholder", 1, 1, "Does nothing", 1));
        p2Display.emplace_back(display_ritual("Placeholder", 1, 1, "Does nothing", 1));
        p2Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p2Display.emplace_back(display_player_card(2, gameState->getPlayer2()->getName(), gameState->getPlayer2()->getLife(), gameState->getPlayer2()->getMagic()));
        p2Display.emplace_back(CARD_TEMPLATE_EMPTY);
        p2Display.emplace_back(CARD_TEMPLATE_BORDER);
        displayTopBorder(os);
        displayCards(p1Display, os, true);
        displayCards(p1Minions, os, true);
        for(int x = 0; x < int(CENTRE_GRAPHIC.size()); x++){
            os<<CENTRE_GRAPHIC.at(x)<<endl;
        }
        displayCards(p2Minions, os, true);
        displayCards(p2Display, os, true);
        displayBottomBorder(os);
    }
    else if(gameState->getCurrentStatus() == CurrentStatus::SHOW_HAND){
        vector<shared_ptr<AbstractCard>> hand = gameState->getCurrentPlayer()->getHand();
        vector<card_template_t> handGraphics;
        for(auto it : hand){
            handGraphics.emplace_back(it->getGraphics());
        }
        displayCards(handGraphics, os, true);
    }
    else if(gameState->getCurrentStatus() == CurrentStatus::GAME_WON){
        os<<"Game over! Player "<<gameState->getTurn()<<" is the winner."<<endl;
    }
}

TextView::~TextView(){};
