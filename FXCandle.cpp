#include "FXCandle.h"

FXCandle::FXCandle( Adafruit_NeoPixel& pix, uint16_t tickInterval): 
Effect(pix, tickInterval)
{
    randomSeed(analogRead(0));   
    next = 0;
    brightness = 200;
}

uint32_t 
FXCandle::redTone(byte idx) 
{
   return pix.Color(250, idx, 30);
}

void
FXCandle::tick()
{
    Effect::tick();

    if (tickCount>=next) {
        for(int i=0;i<pix.numPixels();i++) {
            pix.setPixelColor(i, redTone(random(140,150)));
        }
        brightness += random(0,11) - 5;
        if (brightness < 180) brightness = 180;
        if (brightness > 250) brightness = 250;
        pix.setBrightness(brightness);
        pix.show();
        
        printf("brigtness: %u\r\n", brightness);
        
        next = tickCount + random(50,150) / tickInterval;
    }

/*
    if (tickCount>=next) {
        uint32_t color = redTone(random(100,150));
        for(int i=0;i<pix.numPixels();i++) {
            pix.setPixelColor(i, color);
        }
        pix.setBrightness(random(100,255));
        pix.show();
        
        next = tickCount + random(20,300) / tickInterval;
    }
*/

/*
    for(int i=0;i<pix.numPixels();i++) {
        pix.setPixelColor(i, pix.Color(25,25,10));
    }
    pix.show();
*/
}





