#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include <vector>

class GameState;
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
        std::shared_ptr<AbstractMinionCard> getFieldMinion(int i) const;
        void drawACard();
        void startTurn();
        const std::vector<std::shared_ptr<AbstractCard>> getDeck();
        const std::vector<std::shared_ptr<AbstractCard>> getHand();
        const std::vector<std::shared_ptr<AbstractMinionCard>> getField();
        void play(GameState *gameState, int i);
        void play(GameState *gameState, int i, int p, std::string t);
        void use(GameState *gameState, int i);
        void use(GameState *gameState, int i, int p, std::string t);
        void attackEnemy(GameState *gameState, int i);
        void attackEnemy(GameState *gameState, int i, int j);
        void addMinionToField(std::shared_ptr<AbstractMinionCard> minion);
        void moveToGraveyard(int i);
        ~Player();
};

#endif
