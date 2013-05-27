#include "FastSPI_LED2.h"
#include "StripController.h"
#include "LEDStrip.h"
#include "Effect.h"
#include "RunningEffect.h"
#include "ColorWipeEffect.h"
#include "FireEffect.h"

// Nb led
#define NUM_LEDS 150
#define NB_STRIPS 2

// Enable controller TM1809 on PIN 6
StripController<6, NUM_LEDS> LED;
struct CRGB * pixels;

LEDStrip strip[NB_STRIPS];
FireEffect effect[NB_STRIPS];

struct CRGB palette[256]; //this will contain the color palette

int fire[NUM_LEDS];

/**
 * Initialisation
 */
void setup() {
    LED.init();
    Serial.begin(9600);
    Serial.println("Begin");

    pixels = (struct CRGB *) LED.getPixels();

    strip[0].setPixels(pixels, 75);
    effect[0].setStrip(strip[0]);
    
    strip[1].setPixels(pixels + 75, 75);
    strip[1].setReverse(true);
    effect[1].setStrip(strip[1]);

    LED.show();
    Serial.println("End Setup");
}

/**
 * The loop
 */
void loop() {
    Serial.println("Loop");
    runEffect();
//    effect[0].start(getColor());
//    effect[0].start(Color(127, 127, 127)); // white
//    effect[1].start(Color(127, 127, 127)); // white
//    runEffect();
/*    effect[0].start(Color(127, 0, 0)); // red
    effect[1].start(Color(0, 127, 127)); // cyan
    runEffect();
    effect[0].start(Color(0, 127, 0)); // green
    effect[1].start(Color(127, 0, 127)); // magenta
    runEffect();
    effect[0].start(Color(0, 0, 127)); // blue
    effect[1].start(Color(127, 127, 0)); // yellow
    runEffect();
    */
}   // loop

struct CRGB getColor()
{
    return HSL( ((float) analogRead(A1)) / 1024, 1, ((float) analogRead(A2)) / 1024);
}

int getInterval()
{
    return analogRead(A0) / 4;
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




