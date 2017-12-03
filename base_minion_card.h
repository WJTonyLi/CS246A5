#ifndef BASE_MINION_CARD_H
#define BASE_MINION_CARD_H

#include <memory>
#include "activated_effect.h"
#include "triggered_effect.h"
#include "abstract_minion_card.h"

class BaseMinionCard:public AbstractMinionCard{
        std::shared_ptr<ActivatedEffect> activeAbility;
        std::shared_ptr<TriggeredEffect> triggeredAbility;
        bool hasActivated;
        bool hasTriggered;
    public:
        BaseMinionCard(std::string name, int cost, Player *player, int attack, int defense);
        BaseMinionCard(std::string name, int cost, Player *player, int attack, int defense, std::shared_ptr<ActivatedEffect> activeAbility);
        BaseMinionCard(std::string name, int cost, Player *player, int attack, int defense, std::shared_ptr<TriggeredEffect> triggeredAbility);
        void play(GameState *gameState) override;
        void play(GameState *gameState, int p, std::string t) override;
        void use(GameState *gameState) override;
        void use(GameState *gameState, int p, std::string t) override;
        card_template_t getGraphics() const override;
        ~BaseMinionCard();
};

#endif
