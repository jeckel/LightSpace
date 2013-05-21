// Load requirements
#include "Effect.h"

/**
 * Initialize parameters for all constructor
 */
void Effect::init()
{
    current_step = 0;
    started      = false;
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
