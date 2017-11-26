#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "abstract_card.h"
#include "base_minion_card.h"

class Player{
        int life;
        int magic;
        std::vector<AbstractCard> deck;
        std::vector<AbstractCard> hand;
        std::vector<AbstractMinionCard> field;
        std::vector<AbstractMinionCard> graveyard;
    public:
        Player();
        ~Player();
};

#endif
