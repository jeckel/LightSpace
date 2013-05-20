#include "FastSPI_LED2.h"
#include "LEDStrip.h"
#include "RunningEffect.h"

// Nb led
#define NUM_LEDS 150

// Enable controller TM1809 on PIN 6
TM1809Controller800Mhz<6> LED;
struct CRGB * pixels;

LEDStrip strip = LEDStrip();
RunningEffect effect;

/**
 * Initialisation
 */
void setup() {
    pixels = (struct CRGB *) malloc(NUM_LEDS * sizeof(struct CRGB));
    memset(pixels, 0, NUM_LEDS * sizeof(struct CRGB));
    strip.setPixels(pixels, NUM_LEDS);
//    strip.setReverse(true);
    effect = RunningEffect(strip);
  
    LED.init();
    LED.showRGB((byte *)pixels, NUM_LEDS);
}

/**
 * The loop
 */
void loop() {
    effect.start(Color(127, 127, 127)); // white
    runEffect();
    effect.start(Color(127, 0, 0)); // red
    runEffect();
    effect.start(Color(0, 127, 0)); // green
    runEffect();
    effect.start(Color(0, 0, 127)); // blue
    runEffect();
}   // loop

/**
 * Loop on an effect
 */
void runEffect() {
    while(effect.isStarted())
    {
        effect.beforePause();
        LED.showRGB((byte *)pixels, NUM_LEDS);
        delay(5);
        effect.afterPause();
        effect.nextStep();
    }
}

