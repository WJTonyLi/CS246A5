#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <memory>
#include <iostream>
#include "observer.h"
#include "subject.h"
#include "game_state.h"

class TextView: public Subject<std::string>, public Observer<void>{
        std::ostream& os;
        std::shared_ptr<GameState> gameState;
    public:
        TextView(std::ostream& os, std::shared_ptr<GameState> gameState);
        void notify(Subject<void> &whoFrom) override;
        ~TextView();
};

#endif
