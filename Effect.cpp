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
        current_step = 0;
        end_reached = false;
    }
}

/**
 * Return true of end of effect has been reached
 * @return boolean
 */
boolean Effect::isEndReached()
{
    return end_reached;
}

/**
 * Return if effect is running or not, this depend on endReached, but can depend on more
 * @return boolean
 */
boolean Effect::isRunning()
{
    return ! isEndReached();
}

/**
 * Move to next LED, taking in account the way (reverse) of the strip.
 *
 * if the end of the strip has been reach, the stop the effect and return false
 * @return boolean
 */
boolean Effect::nextStep()
{
    if (! isRunning()) return false;
    current_step++;
    if (current_step < 0 || current_step >= numLEDs)
    {
        end_reached = true;
        return false;
    } else {
        return true;
    }
}
