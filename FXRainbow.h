#ifndef __FXRainbow_H__
#define __FXRainbow_H__

#include "Effect.h"

class FXRainbow: 
public Effect
{
public:
    FXRainbow( Adafruit_NeoPixel& _pix, uint16_t tickInterval );
    void tick();
private:
    uint16_t offs;
    uint8_t interval;
    uint8_t component(uint16_t offs);
};

#endif // __FXRainbow_H__

