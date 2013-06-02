#ifndef EFFECT_H
#define EFFECT_H

// Load requirements
#include "LEDStrip.h"

class Effect {
    public:
        inline void debug(char* debugString){ 
            Serial.println(debugString); 
        }
        void reset();
        void setStrip(LEDStrip *s);
        boolean isEndReached();
        boolean isRunning();
        void beforePause() {};
        void afterPause() {};
        boolean nextStep();
        
    protected:
        LEDStrip *   strip;
        uint16_t    numLEDs;
        boolean     end_reached;
        uint16_t    current_step;
};

#endif
