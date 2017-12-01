#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <memory>
#include "game_state.h"
#include "observer.h"

class GameController: public Observer<std::string>{
        std::shared_ptr<GameState> gameState;
        bool testMode;
        bool graphics;
    public:
        GameController(std::shared_ptr<GameState> gameState, bool testMode = false, bool graphics = false);
        void notify(Subject<std::string> &whoFrom) override;
        void startGame();
};

#endif
