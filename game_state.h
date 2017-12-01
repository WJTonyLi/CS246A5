#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "player.h"
#include "subject.h"

enum class CurrentStatus{SHOW_BOARD, SHOW_HAND, GET_NAME, HELP_MESSAGE};

class GameState: public Subject<void>{
        Player p1;
        Player p2;
        CurrentStatus status;
        int currentTurn;
    public:
        GameState();
        const Player& getPlayer1();
        const Player& getPlayer2();
        const Player& getCurrentPlayer();
        void setCurrentStatus(CurrentStatus status);
        void getInfo() const override;
        int getTurn();
        void endTurn();
        void setCurrentPlayerName(std::string newName);
        void renderNow();
        CurrentStatus getCurrentStatus();
        ~GameState();
};

#endif
