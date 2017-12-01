#ifndef RITUAL_CARD_H
#define RITUAL_CARD_H

#include <string>
#include <memory>
#include "abstract_card.h"
#include "triggered_effect.h"

class GameState;

class RitualCard : public AbstractCard{
        int asdf = 5;
        std::shared_ptr<TriggeredEffect> effect;
    public:
        RitualCard(std::string name, int cost, Player *player, std::shared_ptr<TriggeredEffect> effect);
        card_template_t getGraphics() const;
        void play(GameState *gameState) override;
        void play(GameState *gameState, int p, std::string t) override;
        ~RitualCard();
};

#endif
