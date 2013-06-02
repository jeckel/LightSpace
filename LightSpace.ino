#include "FastSPI_LED2.h"
#include "StripController.h"
#include "LEDStrip.h"
#include "Effect.h"
#include "RunningEffect.h"
#include "ColorWipeEffect.h"
#include "FireEffect.h"

// Nb led
#define NUM_LEDS 180
#define NB_STRIPS 2
// Enable controller TM1809 on PIN 6
StripController<6, NUM_LEDS> LED;
struct CRGB * pixels;

LEDStrip strip[NB_STRIPS];
FireEffect effect[NB_STRIPS];


/**
 * Initialisation
 */
void setup() {
    LED.init();
    pixels = (struct CRGB *) LED.getPixels();

//    strip[0].setPixels(pixels, 75);
//    strip[0].setPixels(pixels, NUM_LEDS);
    strip[0].setPixels(pixels, 90);
    effect[0].setStrip(&strip[0]);
    
    strip[1].setPixels(pixels + 90, 90);
    strip[1].setReverse(true);
    effect[1].setStrip(&strip[1]);
    LED.show();
    
    randomSeed(analogRead(0));
}

/**
 * The loop
 */
void loop() {
/*    effect[0].start(Color(127, 127, 127)); // white
    effect[1].start(Color(127, 127, 127)); // white 
/*    effect[2].start(Color(127, 127, 127)); // white
    effect[3].start(Color(127, 127, 127)); // white
    effect[4].start(Color(127, 127, 127)); // white  */
    runEffect();
}   // loop

int getInterval()
{
//    return analogRead(A0) / 4;
    return 0;
}

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
//        delay(5);
        delay(getInterval());
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].afterPause();
            effect[i].nextStep();
            end_reached &= effect[i].isEndReached();
        }
    }
}




