#ifndef STRIPCONTROLLER_H
#define STRIPCONTROLLER_H

#include "FastSPI_LED2.h"

template <int DATA_PIN, uint16_t NUM_LED>
class StripController : public TM1809Controller800Mhz<DATA_PIN> {
    public :
        void getNumLeds() { return NUM_LED; };
        void init() {
            pixels = (byte *) malloc(NUM_LED * 3);
            memset(pixels, 0, NUM_LED * sizeof(struct CRGB));
            TM1809Controller800Mhz<DATA_PIN>::init();
        };
        byte * getPixels() { return pixels; };
        void show() {
            TM1809Controller800Mhz<DATA_PIN>::showRGB(pixels, NUM_LED);
        };
    private :
        byte * pixels;
};

#endif
