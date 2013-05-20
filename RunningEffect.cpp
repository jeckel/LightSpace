#include "RunningEffect.h"

/**
 * Simple constructor
 */
RunningEffect::RunningEffect()
{
    init();
}

/**
 * Constructor with strip
 * @param LEDStrip s
 */
RunningEffect::RunningEffect(LEDStrip s)
{
    setStrip(s);
    init();
}

/**
 * Initialize parameters for all constructor
 */
void RunningEffect::init()
{
    current_step = 0;
    started      = false;
}

/**
 * Set LED Strip
 * @param LEDStrip s
 */
void RunningEffect::setStrip(LEDStrip s)
{
    strip   = s;
    numLEDs = strip.numPixels();
}

/**
 * Start the effect, must be done after each end of the effect
 * @param struct CRGB c Color to light the LED
 */
void RunningEffect::start(struct CRGB c)
{
    strip.setStrip(0);
    color   = c;
    started = true;
    if (strip.isReverse()) {
        current_step = numLEDs - 1;
    } else {
        current_step = 0;
    }
}

/**
 * Return if the current effect has been initialised and started, will return false if effect has ended
 * @return bool
 */
boolean RunningEffect::isStarted()
{
    return started;
}

/**
 * Execute changes that have to be made after the "delay", it means turn ON the led
 */
void RunningEffect::beforePause()
{
    strip.setPixelColor(current_step, color);
}

/**
 * Execute changes that have to be made after the "delay", it means turn OFF the led
 */
void RunningEffect::afterPause()
{
    strip.setPixelColor(current_step, Color(0, 0, 0));
}

/**
 * Move to next LED, taking in account the way (reverse) of the strip.
 *
 * if the end of the strip has been reach, the stop the effect and return true
 * @return boolean
 */
boolean RunningEffect::nextStep()
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
