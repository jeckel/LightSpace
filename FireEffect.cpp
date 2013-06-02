#include "FireEffect.h"
#include "Color.h"

FireEffect::FireEffect()
{
}

/**
 * Set LED Strip
 * @param LEDStrip s
 */
void FireEffect::setStrip(LEDStrip *s)
{
    Serial.println("setStrip");
//    memset(fire, 0, s->numPixels());
    memset(fire, 0, 90);
    Effect::setStrip(s);
}

/**
 * Execute changes that have to be made after the "delay", it means turn ON the led
 */
void FireEffect::beforePause()
{
//    Serial.println("beforePause");
    if (isRunning())
    {
        fire[0] = random(255);
        for(int x = (numLEDs - 1); x > 0; x--)
        {
            fire[x] = ((fire[x - 1] + fire[(x - 2) % numLEDs]) * (numLEDs / 2)) / (numLEDs * 1.045);
        }
        for(int x=0; x < numLEDs; x++) {
            strip->setPixelColor(x, getFireColorFromPalette(fire[x]));
        }
    }
}

