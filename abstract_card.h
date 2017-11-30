#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include <memory>
#include <string>
#include "ascii_graphics.h"

class Player;

class AbstractCard{
        std::string name;
        int cost;
        std::shared_ptr<Player> owner;
    public:
        AbstractCard(std::string name, int cost, std::shared_ptr<Player> player);
        std::string getName();
        int getCost();
        virtual card_template_t getGraphics() = 0;
        virtual ~AbstractCard();
};

#endif
