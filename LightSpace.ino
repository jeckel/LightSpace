#include "FastSPI_LED2.h"
#include "StripController.h"
#include "LEDStrip.h"
#include "Effect.h"
#include "RunningEffect.h"
#include "ColorWipeEffect.h"
#include "FireEffect.h"

// Nb led
//#define NUM_LEDS 450
//#define NB_STRIPS 5
#define NUM_LEDS 630
#define NB_STRIPS 7
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

    strip[0].setPixels(pixels, 90);
    effect[0].setStrip(&strip[0]);
/*    effect[0].color  = Color(127, 127, 127);
    effect[0].length = 10;
    effect[0].rewind = true;
    */
    strip[1].setPixels(pixels + 90, 90);
    strip[1].setReverse(true);
    effect[1].setStrip(&strip[1]);
/*    effect[1].color  = Color(255, 0, 0);
    effect[1].rewind = true;
    effect[1].length = 0;
*/
    strip[2].setPixels(pixels + 180, 90);
    effect[2].setStrip(&strip[2]);
/*    effect[2].color  = Color(0, 255, 0);
    effect[2].length = 1;
*/    
    strip[3].setPixels(pixels + 270, 90);
    strip[3].setReverse(true);
    effect[3].setStrip(&strip[3]);
/*    effect[3].color  = Color(0, 0, 255);
    effect[3].length = 1;
*/
    strip[4].setPixels(pixels + 360, 90);
    effect[4].setStrip(&strip[4]);
/*    effect[4].color  = Color(255, 255, 0);
    effect[4].length = 10;
  */  

    strip[5].setPixels(pixels + 450, 90);
    strip[5].setReverse(true);
    effect[5].setStrip(&strip[5]);
    
    strip[6].setPixels(pixels + 540, 90);
    effect[6].setStrip(&strip[6]);

    LED.show();
    
    randomSeed(analogRead(0));
}

/**
 * The loop
 */
void loop() {
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
        delay(getInterval());
        for(int i=0; i < NB_STRIPS; i++) {
            effect[i].afterPause();
            effect[i].nextStep();
            end_reached &= effect[i].isEndReached();
        }
    }
}




