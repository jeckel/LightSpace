#include "FastSPI_LED2.h"
#include "StripController.h"
#include "LEDStrip.h"
#include "Effect.h"
#include "RunningEffect.h"
#include "ColorWipeEffect.h"

// Nb led
#define NUM_LEDS 150
#define NB_STRIPS 2

// Enable controller TM1809 on PIN 6
StripController<6, NUM_LEDS> LED;
struct CRGB * pixels;

LEDStrip strip[NB_STRIPS];
RunningEffect effect[NB_STRIPS];

/**
 * Initialisation
 */
void setup() {
    LED.init();
    Serial.begin(9600);
    Serial.println(sizeof(struct CRGB));
    pixels = (struct CRGB *) LED.getPixels();

    strip[0] = LEDStrip();
    strip[0].setPixels(pixels, 75);
    strip[1] = LEDStrip();
    strip[1].setPixels(pixels + 75, 75);
    strip[1].setReverse(true);
    
    for(int i = 0; i < NB_STRIPS; i++)
    {
        effect[i] = RunningEffect(strip[i]);
    }
  
    LED.show();
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
    boolean end_reached = false;
    for(int i=0; i < NB_STRIPS; i++)
    {
        effect[i].reset();
    }
    
    while(! end_reached)
    {
        end_reached = true;
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].beforePause();
        }
        LED.show();
        delay(5);
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].afterPause();
            effect[i].nextStep();
            end_reached &= effect[i].isEndReached();
        }
    }
}

