#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "abstract_card.h"
#include "abstract_minion_card.h"

class AbstractCard;
class AbstractMinionCard;

class Player{
        int life;
        int magic;
        std::string name;
        std::vector<AbstractCard> deck;
        std::vector<AbstractCard> hand;
        std::vector<AbstractMinionCard> field;
        std::vector<AbstractMinionCard> graveyard;
    public:
        Player();
        void setName(std::string name);
        int getLife() const;
        int setLife(int life);
        int getMagic() const;
        int setMagic(int magic);
        std::string getName() const;
        ~Player();
};

#endif
