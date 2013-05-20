#include "FastSPI_LED2.h"
#include "LEDStrip.h"
#include "RunningEffect.h"

// Nb led
#define NUM_LEDS 150

// Enable controller TM1809 on PIN 6
TM1809Controller800Mhz<6> LED;
struct CRGB * pixels;

LEDStrip strip1 = LEDStrip();
LEDStrip strip2 = LEDStrip();
RunningEffect effect1, effect2;

/**
 * Initialisation
 */
void setup() {
    pixels = (struct CRGB *) malloc(NUM_LEDS * sizeof(struct CRGB));
    memset(pixels, 0, NUM_LEDS * sizeof(struct CRGB));

    strip1.setPixels(pixels, 75);
    strip2.setPixels(pixels + 75, 75);
    strip2.setReverse(true);
    
    effect1 = RunningEffect(strip1);
    effect2 = RunningEffect(strip2);
  
    LED.init();
    LED.showRGB((byte *)pixels, NUM_LEDS);
}

/**
 * The loop
 */
void loop() {
    effect1.start(Color(127, 127, 127)); // white
    effect2.start(Color(127, 127, 127)); // white
    runEffect();
    effect1.start(Color(127, 0, 0)); // red
    effect2.start(Color(0, 127, 127)); // cyan
    runEffect();
    effect1.start(Color(0, 127, 0)); // green
    effect2.start(Color(127, 0, 127)); // magenta
    runEffect();
    effect1.start(Color(0, 0, 127)); // blue
    effect2.start(Color(127, 127, 0)); // yellow
    runEffect();
}   // loop

/**
 * Loop on an effect
 */
void runEffect() {
    while(effect1.isStarted() && effect2.isStarted())
    {
        effect1.beforePause();
        effect2.beforePause();
        LED.showRGB((byte *)pixels, NUM_LEDS);
        delay(5);
        effect1.afterPause();
        effect1.nextStep();
        effect2.afterPause();
        effect2.nextStep();
    }
}

