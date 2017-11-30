#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
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
        std::vector<std::shared_ptr<AbstractCard>> deck;
        std::vector<std::shared_ptr<AbstractCard>> hand;
        std::vector<std::shared_ptr<AbstractMinionCard>> field;
        std::vector<std::shared_ptr<AbstractMinionCard>> graveyard;
    public:
        Player();
        Player(std::string deckFileName);
        void setName(std::string name);
        int getLife() const;
        void setLife(int life);
        int getMagic() const;
        void setMagic(int magic);
        std::string getName() const;
        void drawACard();
        void playCard(int index);
        void startTurn();
        const std::vector<std::shared_ptr<AbstractCard>> getDeck() const;
        const std::vector<std::shared_ptr<AbstractCard>> getHand() const;
        ~Player();
};

#endif
