#include "FXRotate.h"

FXRotate::FXRotate( Adafruit_NeoPixel& pix, uint16_t tickInterval): 
Effect(pix, tickInterval)
{
    offs = 0;
    interval = 70 / tickInterval;
}

void
FXRotate::tick()
{
    Effect::tick();
    
    if (tickCount % interval == 0) {
        for(int i=0;i<pix.numPixels();i++) {
            uint8_t pos = (i-offs)%pix.numPixels();
            if (pos<2) {
                pix.setPixelColor(i, pix.Color(255,50,50));
            } else if (pos==4 || pos==5) {
                pix.setPixelColor(i, pix.Color(255,255,200));
            } else {
                pix.setPixelColor(i, pix.Color(0,0,0));
            }
        }
        pix.show();
        offs ++;
    }

}



