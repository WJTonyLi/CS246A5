#ifndef ABSTRACT_CARD_H
#define ABSTRACT_CARD_H

#include <string>

class AbstractCard{
        std::string name;
        int cost;
    public:
        AbstractCard();
        virtual ~AbstractCard();
};

#endif
