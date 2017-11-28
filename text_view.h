#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include <memory>
#include <iostream>
#include "subject.h"
#include "game_state.h"

class TextView: public Subject<std::string>{
        std::istream& is;
        std::ostream& os;
        std::shared_ptr<GameState> gameState;
    public:
        TextView(std::istream& is, std::ostream& os, std::shared_ptr<GameState> gameState);
        std::string getInfo() const override;
        void test();
        ~TextView();
};

#endif