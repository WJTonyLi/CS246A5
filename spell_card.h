#ifndef SPELL_CARD_H
#define SPELL_CARD_H

#include <string>
#include <memory>
#include "abstract_card.h"
#include "activated_effect.h"

class GameState;

class SpellCard:public AbstractCard{
        int asdf = 5;
        std::shared_ptr<ActivatedEffect> effect;
    public:
        SpellCard(std::string name, int cost, Player *player, std::shared_ptr<ActivatedEffect> effect);
        card_template_t getGraphics() const;
        void play(GameState *gameState) override;
        void play(GameState *gameState, int p, std::string t) override;
        ~SpellCard();
};

#endif
