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
RunningEffect::RunningEffect(LEDStrip s)
{
    setStrip(s);
}

/**
 * Start the effect, must be done after each end of the effect
 * @param struct CRGB c Color to light the LED
 */
void RunningEffect::start(struct CRGB c)
{
    strip.setStrip(0);
    color   = c;
    reset();
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

