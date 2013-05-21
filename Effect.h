#ifndef EFFECT_H
#define EFFECT_H

// Load requirements
#include "LEDStrip.h"

class Effect {
    public:
        inline void debug(char* debugString){ 
            Serial.println(debugString); 
        }
        void setStrip(LEDStrip s);
        boolean isStarted();
        void beforePause() {};
        void afterPause() {};
        boolean nextStep();
        
    protected:
        LEDStrip    strip;
        uint16_t    numLEDs;
        boolean     started;
        uint16_t    current_step;
        
        void init();
};

#endif
