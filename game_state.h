#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "player.h"

class GameState{
        std::shared_ptr<Player> p1;
        std::shared_ptr<Player> p2;
    public:
        GameState();
        std::shared_ptr<const Player> getPlayer1();
        std::shared_ptr<const Player> getPlayer2();
        ~GameState();
};

#endif
