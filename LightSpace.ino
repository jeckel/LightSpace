#include "FastSPI_LED2.h"
#include "LEDStrip.h"

// Nb led
#define NUM_LEDS 150

// Enable controller TM1809 on PIN 6
TM1809Controller800Mhz<6> LED;
struct CRGB * pixels;

LEDStrip strip = LEDStrip();

/**
 * Initialisation
 */
void setup() {
    pixels = (struct CRGB *) malloc(NUM_LEDS * sizeof(struct CRGB));
    memset(pixels, 0, NUM_LEDS * sizeof(struct CRGB));
    strip.setPixels(pixels, NUM_LEDS);
  
    LED.init();
    LED.showRGB((byte *)pixels, NUM_LEDS);
}

/**
 * The loop
 */
void loop() {
    for(int i = 0; i < NUM_LEDS; i++)
    {
        strip.setPixelColor(i, Color(127, 127, 127));
        LED.showRGB((byte *)pixels, NUM_LEDS);
        delay(5);
        strip.setPixelColor(i, Color(0, 0, 0));
    }   // for
}   // loop

