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
    strip.setReverse(true);
  
    LED.init();
    LED.showRGB((byte *)pixels, NUM_LEDS);
}

/**
 * The loop
 */
void loop() {
    int led = 0;
    for(int i = 0; i < NUM_LEDS; i++)
    {
        led = (strip.isReverse()) ? NUM_LEDS - i : i;
        strip.setPixelColor(led, Color(127, 127, 127));
        LED.showRGB((byte *)pixels, NUM_LEDS);
        delay(5);
        strip.setPixelColor(led, Color(0, 0, 0));
    }   // for
}   // loop

