#include "ColorWipeEffect.h"

/**
 * Simple constructor
 */
ColorWipeEffect::ColorWipeEffect()
{
    init();
}

/**
 * Constructor with strip
 * @param LEDStrip s
 */
ColorWipeEffect::ColorWipeEffect(LEDStrip s)
{
    setStrip(s);
    init();
}

/**
 * Start the effect, must be done after each end of the effect
 * @param struct CRGB c Color to light the LED
 */
void ColorWipeEffect::start(struct CRGB c)
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
 * Execute changes that have to be made after the "delay", it means turn ON the led
 */
void ColorWipeEffect::beforePause()
{
    strip.setPixelColor(current_step, color);
}


