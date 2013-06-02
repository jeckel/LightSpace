#include "RunningEffect.h"

/**
 * Simple constructor
 */
RunningEffect::RunningEffect()
{
}

/**
 * Constructor with strip
 * @param LEDStrip s
 */
RunningEffect::RunningEffect(LEDStrip *s)
{
    setStrip(s);
}

/**
 * Start the effect, must be done after each end of the effect
 * @param struct CRGB c Color to light the LED
 */
void RunningEffect::reset()
{
    strip->setStrip(0);
//    if (length <= 0) length = 1;
    returning = false;
    Effect::reset();
}

/**
 * Execute changes that have to be made after the "delay", it means turn ON the led
 */
void RunningEffect::beforePause()
{
    if (isRunning())
    {
/*        if (length > 0) {
            for(byte i = length; i > 0 && (current_step - i) >= 0; i--) {
                strip->setPixelColor(current_step - i, color);
            }
        } else { */
            strip->setPixelColor(current_step, color);
/*        } */
    }
}

/**
 * Execute changes that have to be made after the "delay", it means turn OFF the led
 */
void RunningEffect::afterPause()
{
    if (isRunning())
    {
        if (!returning && current_step >= length) {
            if (length > 0)
                strip->setPixelColor(current_step - length, Color(0, 0, 0));
        } else if (returning) {
            strip->setPixelColor(current_step + length, Color(0, 0, 0));
        }
    }
}

/**
 * Move to next LED, taking in account the way (reverse) of the strip.
 *
 * if the end of the strip has been reach, the stop the effect and return false
 * @return boolean
 */
boolean RunningEffect::nextStep()
{
    if (! isRunning()) return false;
    if (returning)
        current_step--;
    else
        current_step++;
    if (current_step > (numLEDs + length) && rewind) {
        returning = true;
        return true;
    }
    if (current_step <= 0 || current_step > (numLEDs + length))
    {
        returning = false;
        end_reached = true;
        return false;
    } else {
        return true;
    }
}

