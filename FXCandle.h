#ifndef __FXCandle_H__
#define __FXCandle_H__

#include "Effect.h"

class FXCandle: 
public Effect
{
public:
    FXCandle( Adafruit_NeoPixel& _pix, uint16_t tickInterval );
    void tick();
protected:
    virtual uint32_t redTone(byte idx);
private:
    uint32_t next;
    uint8_t brightness;
};

#endif // __FXCandle_H__

