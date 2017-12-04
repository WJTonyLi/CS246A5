#ifndef RITUAL_CARD_H
#define RITUAL_CARD_H

#include <string>
#include <memory>
#include "abstract_card.h"
#include "triggered_effect.h"
#include "player.h"

class GameState;

class RitualCard : public AbstractCard, public RawPtrObserver<Event>{
        std::shared_ptr<TriggeredEffect> effect;
        std::string description;
        int charges;
        int activationCost;
    public:
        RitualCard(std::string name, int cost, Player *player, std::string description, int activationCost, int charges);
        std::string getDescription();
        card_template_t getGraphics() const;
        void conditionMet();
        void addCharges(int amount);
        virtual void play(GameState *gameState) = 0;
        virtual void play(GameState *gameState, int p, std::string t) = 0;
        virtual void deactivate() = 0;
        virtual void applyEffects() = 0;
        card_template_t getGraphics();
        ~RitualCard();
};

#endif
