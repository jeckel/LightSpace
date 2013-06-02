#ifndef COLORWIPEEFFECT_H
#define COLORWIPEEFFECT_H

// Load requirements
#include "LEDStrip.h"
#include "Effect.h"

/**
 * Running Effect class declaration
 * 
 * This effect is a single LED running along the whole strip in the way of the strip (using reverse option)
 */
class ColorWipeEffect : public Effect {
    public:
        ColorWipeEffect();
        ColorWipeEffect(LEDStrip *s);
        void start(struct CRGB c);
        void beforePause();
    
    private:
        struct CRGB color;
};


#endif
