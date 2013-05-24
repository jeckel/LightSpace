#include "Color.h"

/**
 * Convert separate R,G,B into combined 32-bit GRB
 * @param  byte r Red color
 * @param  byte g Green color
 * @param  byte b Blue color
 * @return struct CRGB
 */
struct CRGB Color(byte r, byte g, byte b)
{
    struct CRGB led;
    led.r = r;
    led.g = g;
    led.b = b;
    return led;
};

/**
 * Calculate R G B from Hue
 * @param  float v1
 * @param  float v2
 * @param  float vH
 * @return float
 */
float Hue_2_RGB( float v1, float v2, float vH )             //Function Hue_2_RGB
{
    if ( vH < 0 ) 
        vH += 1;
    if ( vH > 1 ) 
        vH -= 1;
    if ( ( 6 * vH ) < 1 ) 
        return ( v1 + ( v2 - v1 ) * 6 * vH );
    if ( ( 2 * vH ) < 1 ) 
        return ( v2 );
    if ( ( 3 * vH ) < 2 ) 
        return ( v1 + ( v2 - v1 ) * (.66-vH) * 6 );
    return ( v1 );
}

/**
 * Calculate RGB color from Hue/Saturation/Lightness
 * @param  float H     Hue from 0 to 1
 * @param  float S     Saturation from 0 to 1
 * @param  float L     Lightness from 0 to 1
 * @return struct CRGB
 */
struct CRGB HSL(float H, float S, float L)
{
    struct CRGB color;
    float var_1;
    float var_2;
    float Hu=H+.33;
    float Hd=H-.33;
    if ( S == 0 )                       //HSL from 0 to 1
    {
        color.r = L * 255;                      //RGB results from 0 to 255
        color.g = L * 255;
        color.b = L * 255;
    }
    else
    {
        if ( L < 0.5 ) 
            var_2 = L * ( 1 + S );
        else
            var_2 = ( L + S ) - ( S * L );
        var_1 = 2 * L - var_2;
        color.r = round(255 * Hue_2_RGB( var_1, var_2, Hu ));
        color.g = round(255 * Hue_2_RGB( var_1, var_2, H ));
        color.b = round(255 * Hue_2_RGB( var_1, var_2, Hd ));
    }
    return color;
}
