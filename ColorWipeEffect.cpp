#include "ColorWipeEffect.h"

/**
 * Simple constructor
 */
ColorWipeEffect::ColorWipeEffect()
{
}

/**
 * Constructor with strip
 * @param LEDStrip s
 */
ColorWipeEffect::ColorWipeEffect(LEDStrip s)
{
    setStrip(s);
}

/**
 * Start the effect, must be done after each end of the effect
 * @param struct CRGB c Color to light the LED
 */
void ColorWipeEffect::start(struct CRGB c)
{
    strip.setStrip(0);
    color   = c;
    reset();
}

/**
 * Execute changes that have to be made after the "delay", it means turn ON the led
 */
void ColorWipeEffect::beforePause()
{
    if (isRunning())
    {
        strip.setPixelColor(current_step, color);
    }
}


