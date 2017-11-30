#ifndef ACTIVATED_EFFECT_H
#define ACTIVATED_EFFECT_H

#include <string>

class ActivatedEffect{
        std::string description;
    public:
        ActivatedEffect(std::string description);
        virtual ~ActivatedEffect();
};

#endif
