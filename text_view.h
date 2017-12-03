#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <memory>
#include <iostream>
#include "shared_ptr_observer.h"
#include "shared_ptr_subject.h"
#include "game_state.h"

class TextView: public SharedPtrObserver<void>{
        std::ostream& os;
        std::shared_ptr<GameState> gameState;
    public:
        TextView(std::ostream& os, std::shared_ptr<GameState> gameState);
        void notify(SharedPtrSubject<void> &whoFrom) override;
        ~TextView();
};

#endif
