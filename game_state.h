#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "player.h"
#include "subject.h"

enum class RenderMode{BOARD, HAND, GET_NAME};

class GameState: public Subject<void>{
        std::shared_ptr<Player> p1;
        std::shared_ptr<Player> p2;
        RenderMode renderMode;
        int currentTurn;
    public:
        GameState();
        std::shared_ptr<const Player> getPlayer1();
        std::shared_ptr<const Player> getPlayer2();
        void setRenderMode(RenderMode mode);
        void getInfo() const override;
        RenderMode getRenderMode();
        ~GameState();
};

#endif
