#ifndef COLORWIPEEFFECT_H
#define COLORWIPEEFFECT_H

// Load requirements
#include "LEDStrip.h"

/**
 * Running Effect class declaration
 * 
 * This effect is a single LED running along the whole strip in the way of the strip (using reverse option)
 */
class ColorWipeEffect {
    public:
        ColorWipeEffect();
        ColorWipeEffect(LEDStrip s);
        void setStrip(LEDStrip s);
        void start(struct CRGB c);
        void beforePause();
        void afterPause();
        boolean nextStep();
        boolean isStarted();
    
    private:
        LEDStrip    strip;
        uint16_t    numLEDs;
        boolean     started;
        uint16_t    current_step;
        struct CRGB color;
    
        void init();
};


#endif
