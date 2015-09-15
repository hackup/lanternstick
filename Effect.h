#ifndef __Effect_H__
#define __Effect_H__

#include <Adafruit_NeoPixel.h>

class Effect
{
public:
    Effect(Adafruit_NeoPixel& pix, uint16_t tickInterval): pix(pix), tickInterval(tickInterval)
    {
        tickCount = 0;
    }
    virtual void tick() 
    {
        tickCount++;
    };
protected:
    Adafruit_NeoPixel& pix; 
    uint16_t tickInterval;
    uint32_t tickCount;
};

#endif // __Effect_H__

