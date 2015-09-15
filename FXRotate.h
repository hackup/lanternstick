#ifndef __FXRotate_H__
#define __FXRotate_H__

#include "Effect.h"

class FXRotate: 
public Effect
{
public:
    FXRotate( Adafruit_NeoPixel& _pix, uint16_t tickInterval );
    void tick();
private:
    uint8_t offs;
    uint8_t interval;
};

#endif // __FXRotate_H__

