#include "FastSPI_LED2.h"
#include "LEDStrip.h"
#include "RunningEffect.h"

// Nb led
#define NUM_LEDS 150
#define NB_STRIPS 2

// Enable controller TM1809 on PIN 6
TM1809Controller800Mhz<6> LED;
struct CRGB * pixels;

LEDStrip strip[NB_STRIPS];
RunningEffect effect[NB_STRIPS];

/**
 * Initialisation
 */
void setup() {
    // Allocate memory for pixels, this is the memory range that will be sent directly to the TM1809
    pixels = (struct CRGB *) malloc(NUM_LEDS * sizeof(struct CRGB));
    memset(pixels, 0, NUM_LEDS * sizeof(struct CRGB));

    strip[0] = LEDStrip();
    strip[0].setPixels(pixels, 75);
    strip[1] = LEDStrip();
    strip[1].setPixels(pixels + 75, 75);
    strip[1].setReverse(true);
    
    for(int i = 0; i < NB_STRIPS; i++)
    {
        effect[i] = RunningEffect(strip[i]);
    }
  
    LED.init();
    LED.showRGB((byte *)pixels, NUM_LEDS);
}

/**
 * The loop
 */
void loop() {
    effect[0].start(Color(127, 127, 127)); // white
    effect[1].start(Color(127, 127, 127)); // white
    runEffect();
    effect[0].start(Color(127, 0, 0)); // red
    effect[1].start(Color(0, 127, 127)); // cyan
    runEffect();
    effect[0].start(Color(0, 127, 0)); // green
    effect[1].start(Color(127, 0, 127)); // magenta
    runEffect();
    effect[0].start(Color(0, 0, 127)); // blue
    effect[1].start(Color(127, 127, 0)); // yellow
    runEffect();
}   // loop

/**
 * Loop on an effect
 */
void runEffect() {
    boolean isStarted = true;
    while(isStarted)
    {
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].beforePause();
        }
        LED.showRGB((byte *)pixels, NUM_LEDS);
        delay(5);
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].afterPause();
            effect[i].nextStep();
            isStarted &= effect[i].isStarted();
        }
    }
}

