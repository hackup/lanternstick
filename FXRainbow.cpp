#include "FXRainbow.h"

FXRainbow::FXRainbow( Adafruit_NeoPixel& pix, uint16_t tickInterval): 
Effect(pix, tickInterval)
{
    offs = 0;
    interval = 10 / tickInterval;
}

uint8_t
FXRainbow::component(uint16_t offs)
{
    uint16_t c = (offs)%512;
    if (c>255) c = 511-c;
    return (uint8_t)c;
}

void
FXRainbow::tick()
{
    Effect::tick();

    if (tickCount % interval == 0) {
        uint8_t r = component(offs);
        uint8_t g = component(offs*3+170);
        uint8_t b = component(offs*5+340);
        for(int i=0;i<pix.numPixels();i++) {
            pix.setPixelColor(i, pix.Color(r,g,b));
        }
        //printf("color: %u %u %u\r\n", r,g,b);
        pix.show();
        offs+=1;
    }

}




