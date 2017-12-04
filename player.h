#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>
#include <vector>
#include "raw_ptr_subject.h"

class GameState;
class AbstractCard;
class AbstractMinionCard;
class RitualCard;

enum class EventType{MINION_ENTERED, MINION_LEFT, BEGINNING_TURN, ENDING_TURN};

class Event{
        EventType eventType;
        std::shared_ptr<AbstractMinionCard> minion;
    public:
        Event(EventType eventType);
        Event(EventType eventType, std::shared_ptr<AbstractMinionCard> minion);
        EventType getEventType();
        std::shared_ptr<AbstractMinionCard> getMinion();
};

class Player: public RawPtrSubject<Event>{
        int life;
        int magic;
        std::string name;
        std::vector<std::shared_ptr<AbstractCard>> deck;
        std::vector<std::shared_ptr<AbstractCard>> hand;
        std::vector<std::shared_ptr<AbstractMinionCard>> field;
        std::vector<std::shared_ptr<AbstractMinionCard>> graveyard;
        Event lastEvent;
        bool hasActiveRitual = false;
        std::shared_ptr<RitualCard> activeRitual;
    public:
        Player();
        Player(std::string deckFileName);
        Event getInfo() const;
        void setName(std::string name);
        int getLife() const;
        void setLife(int life);
        int getMagic() const;
        void setMagic(int magic);
        std::string getName() const;
        std::shared_ptr<AbstractMinionCard> getFieldMinion(int i) const;
        int getHandCost(int i) const;
        int getFieldMinionCost(int i) const;
        void drawACard();
        void discardCard(int i);
        void startTurn();
        void endTurn();
        const std::vector<std::shared_ptr<AbstractCard>> getDeck();
        const std::vector<std::shared_ptr<AbstractCard>> getHand();
        const std::vector<std::shared_ptr<AbstractMinionCard>> getField();
        void shuffle();
        void play(GameState *gameState, int i);
        void play(GameState *gameState, int i, int p, std::string t);
        void use(GameState *gameState, int i);
        void use(GameState *gameState, int i, int p, std::string t);
        void attackEnemy(GameState *gameState, int i);
        void attackEnemy(GameState *gameState, int i, int j);
        void addMinionToField(std::shared_ptr<AbstractMinionCard> minion);
        void moveToGraveyard(int i);
        bool hasRitualInPlay();
        void setRitual(std::shared_ptr<RitualCard> ritual);
        std::shared_ptr<RitualCard> getRitual() const;
        void removeRitual();
        ~Player();
};

#endif
