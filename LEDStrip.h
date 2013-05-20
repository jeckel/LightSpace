#ifndef LEDStrip_h
#define LEDStrip_h

// Load requirements
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

#include <FastSPI_LED2.h>

// Define the RGB Pixel structure
struct CRGB { byte r; byte g; byte b; };

/**
 * LED Strip class declaration
 */
class LEDStrip {
    public:
        LEDStrip(uint16_t n); 
        LEDStrip();
        void setPixelColor(uint16_t pixel, uint8_t red, uint8_t green, uint8_t blue);
        void setPixelColor(uint16_t pixel, struct CRGB c);
        void setStrip(uint16_t set);
        void setPixels(struct CRGB * p, uint16_t n);
        uint16_t numPixels(void);
        byte* getPixels(void);
//        boolean colorChase(struct CRGB c);

    private:
        struct CRGB * pixels;    // Memory used for LEDStrip datas, this datas will be pushed as is into Arduino
        uint16_t      numLEDs;    // Number of RGB LEDs in strip
        //effect_step;
};

/**
 * Usefull function
 */
struct CRGB Color(byte r, byte g, byte b);

#endif