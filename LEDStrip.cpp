#include "LEDStrip.h"

/**
 * Simple constructor
 */
LEDStrip::LEDStrip()
{
    if(pixels != NULL)
    {
        free(pixels); // Free existing data (if any)
    }
}   // LEDStrip


/**
 * Constructor
 * @param uint16_t n Number of leds in strip
 */
LEDStrip::LEDStrip(uint16_t n)
{
    uint16_t numBytes = n * sizeof(struct CRGB);
    if(pixels != NULL) {
        free(pixels); // Free existing data (if any)
    }
    setPixels((struct CRGB *)malloc(numBytes), n);
}    // LEDStrip(uint16_t n)

/**
 * Set memory allocated to pixels and size of it
 * @param struct CRGB *
 * @param uint16_t
 */
void LEDStrip::setPixels(struct CRGB * p, uint16_t n)
{
    numLEDs  = n;
    pixels = p;
}

/**
 * Define is the strip is running in the right way or in a reverse way (up to down)
 * @param boolean r True if workinf in reverse way
 */
void LEDStrip::setReverse(boolean r)
{
    reverse = r;
}

/**
 * Return if strip is workinf in a reverse way
 * @return boolean
 */
boolean LEDStrip::isReverse()
{
    return reverse;
}

/**
 * Get number of leds in strip
 * @return uint16_t
 */
uint16_t LEDStrip::numPixels(void)
{
    return numLEDs;
}

/**
 * Get memory range of pixels
 */
byte* LEDStrip::getPixels(void)
{
    return (byte*) pixels;
}

/**
 * Set color of a pixel
 * @param uint16_t pixel Pixel number
 * @param uint8_t  red   Red color
 * @param uint8_t  green Green color
 * @param uint8_t  blue  Blue color
 */
void LEDStrip::setPixelColor(uint16_t pixel, uint8_t red, uint8_t green, uint8_t blue)
{
    if (pixel < numLEDs)
    {
        pixels[pixel].r = red;
        pixels[pixel].g = green;
        pixels[pixel].b = blue;
    }   // if
}

/**
 * Set color of a pixel
 * @param uint16_t    pixel Pixel number
 * @param strcut CRGB c     Color
 */
void LEDStrip::setPixelColor(uint16_t pixel, struct CRGB c) {
    if (pixel < numLEDs)
    {
        pixels[pixel].r = c.r;
        pixels[pixel].g = c.g;
        pixels[pixel].b = c.b;
    }
}

/**
 * Set all strip color at one time
 * @param uint16_t set
 */
void LEDStrip::setStrip(uint16_t set)
{
    memset(pixels, set, numLEDs * sizeof(struct CRGB));
}

/**
 * Convert separate R,G,B into combined 32-bit GRB
 * @param byte r Red color
 * @param byte g Green color
 * @param byte b Blue color
 * @return struct CRGB
 */
struct CRGB Color(byte r, byte g, byte b)
{
    struct CRGB led;
    led.r = r;
    led.g = g;
    led.b = b;
    return led;
}

