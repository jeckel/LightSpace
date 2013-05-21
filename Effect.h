#ifndef EFFECT_H
#define EFFECT_H

// Load requirements
#include "LEDStrip.h"

class Effect {
    public:
        inline void debug(char* debugString){ 
            Serial.println(debugString); 
        }
        boolean isStarted();
        virtual void beforePause() = 0;
        void afterPause() {};
        virtual boolean nextStep();
        
    protected:
        LEDStrip    strip;
        uint16_t    numLEDs;
        boolean     started;
        uint16_t    current_step;
        
        void init();
};

#endif
