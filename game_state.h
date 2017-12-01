#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "player.h"
#include "subject.h"

enum class CurrentStatus{SHOW_BOARD, SHOW_HAND, GET_NAME, HELP_MESSAGE};

class GameState: public Subject<void>{
        std::shared_ptr<Player> p1;
        std::shared_ptr<Player> p2;
        CurrentStatus status;
        int currentTurn;
    public:
        GameState();
        std::shared_ptr<Player> getPlayer1();
        std::shared_ptr<Player> getPlayer2();
        std::shared_ptr<Player> getCurrentPlayer();
        void setCurrentStatus(CurrentStatus status);
        void getInfo() const override;
        int getTurn();
        void endTurn();
        void setCurrentPlayerName(std::string newName);
        void renderNow();
        void play(int i);
        void play(int i, int p, std::string t);
        CurrentStatus getCurrentStatus();
        ~GameState();
};

#endif
