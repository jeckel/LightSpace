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
            strip->setPixelColor(x, getPalette(fire[x]));
        }
    }
}

/**
 * Get color from palette
 * @param  byte        x Coordinate in palette
 * @return struct CRGB
 */
struct CRGB FireEffect::getPalette(byte x)
{
    static struct CRGB palette[256];
    static boolean loaded = false;
    
    if (! loaded) {
        for(int x = 0; x < 256; x++)
        {
            //HSLtoRGB is used to generate colors:
            //Hue goes from 0 to 85: red to yellow
            //Saturation is always the maximum: 255
            //Lightness is 0..255 for x=0..128, and 255 for x=128..255
            palette[x] = HSL(x / 3.0 / 255, 1, (x < 128 ? x * 2.0 : 255) / 255);
    //        palette[x] = HSL(x / 3.0 / 255, 1, (x < 128 ? x * 2.0 : 255) / 511);
        }
        loaded = true;
    }
    return palette[x];
}

