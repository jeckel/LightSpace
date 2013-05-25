#ifndef FIREEFFECT_H
#define FIREEFFECT_H

// Load requirements
#include "LEDStrip.h"
#include "Effect.h"
/**
 * Running Effect class declaration
 * 
 * This effect is a single LED running along the whole strip in the way of the strip (using reverse option)
 */
class FireEffect : public Effect {
    public:
        FireEffect();
        void setStrip(LEDStrip s);
        void beforePause();

    private:
        struct CRGB palette[256];
        byte * fire;
        void preparePalette();
};


#endif
