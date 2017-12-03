#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "player.h"
#include "shared_ptr_subject.h"

enum class CurrentStatus{SHOW_BOARD, SHOW_HAND, GET_NAME, HELP_MESSAGE, GAME_WON, GAME_END};

class GameState: public SharedPtrSubject<void>{
        std::shared_ptr<Player> p1;
        std::shared_ptr<Player> p2;
        CurrentStatus status;
        int currentTurn;
    public:
        GameState(std::string deckFile1, std::string deckFile2);
        std::shared_ptr<Player> getPlayer1();
        std::shared_ptr<Player> getPlayer2();
        std::shared_ptr<Player> getCurrentPlayer();
        std::shared_ptr<Player> getCurrentOpponent();
        void setCurrentStatus(CurrentStatus status);
        void getInfo() const override;
        int getTurn();
        void endTurn();
        void setCurrentPlayerName(std::string newName);
        void renderNow();
        void play(int i);
        void play(int i, int p, std::string t);
        void use(int i);
        void use(int i, int p, std::string t);
        void attackEnemy(int i);
        void attackEnemy(int i, int j);
        CurrentStatus getCurrentStatus();
        ~GameState();
};

#endif
