#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include <string>

class Player;

class AbstractCard{
        std::string name;
        int cost;
        Player &owner;
    public:
        AbstractCard(std::string name, int cost, Player& player);
        virtual ~AbstractCard();
};

#endif
