#ifndef RUNNINGEFFECT_H
#define RUNNINGEFFECT_H

// Load requirements
#include "LEDStrip.h"
#include "Effect.h"

/**
 * Running Effect class declaration
 * 
 * This effect is a single LED running along the whole strip in the way of the strip (using reverse option)
 */
class RunningEffect : public Effect {
    public:
        RunningEffect();
        RunningEffect(LEDStrip s);
        void start(struct CRGB c);
        void beforePause();
        void afterPause();
    
    private:
        struct CRGB color;
};


#endif
