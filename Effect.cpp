// Load requirements
#include "Effect.h"


/**
 * Set LED Strip
 * @param LEDStrip s
 */
void Effect::setStrip(LEDStrip s)
{
    strip   = s;
    numLEDs = strip.numPixels();
    reset();
}

/**
 * Reset the effect to its starting position
 */
void Effect::reset()
{
    if (strip.numPixels() != 0) {
        started = true;
        if (strip.isReverse()) {
            current_step = numLEDs - 1;
        } else {
            current_step = 0;
        }
    }
}

/**
 * Return if the current effect has been initialised and started, will return false if effect has ended
 * @return bool
 */
boolean Effect::isStarted()
{
    return started;
}

/**
 * Move to next LED, taking in account the way (reverse) of the strip.
 *
 * if the end of the strip has been reach, the stop the effect and return true
 * @return boolean
 */
boolean Effect::nextStep()
{
    if (! started) return false;
    if (strip.isReverse()) {
        current_step--;
    } else {
        current_step++;
    }
    if (current_step < 0 || current_step >= numLEDs)
    {
        started = false;
        return true;
    } else {
        return false;
    }
}
