#include <limits.h>
#include <OneButton.h>
#include <Adafruit_NeoPixel.h>

#include "myprintf.h"
#include "FXCandle.h"
#include "FXRotate.h"
#include "FXRainbow.h"

#define PIN_BUTTON 2
#define PIN_LEDS   3
#define TICK_INTERVAL 10
#define FX_DURATION 3000

#define MODE_DEFAULT 0
#define MODE_SPECIAL 1

OneButton button(2, true);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN_LEDS, NEO_GRB + NEO_KHZ800);

Effect *fx;
Effect *fxCandle = new FXCandle(strip, TICK_INTERVAL);
Effect *fxRotate = new FXRotate(strip, TICK_INTERVAL);
Effect *fxRainbow = new FXRainbow(strip, TICK_INTERVAL);
Effect *fxDefault = fxCandle;
Effect *fxSpecial = fxRotate;
uint8_t mode;
long lastPress;

void setup() {

    button.attachDoubleClick(doubleclick);
    button.attachLongPressStart(pressStart);
    button.attachLongPressStop(pressStop);

    strip.begin();

    fx = fxDefault;
    mode = MODE_DEFAULT;
    lastPress = -999999;

    Serial.begin(57600);
    printf_begin();
    printf("Fancy Lantern\n\r");
}

void setMode(uint8_t aMode) {
    if (mode!=aMode) {
        mode = aMode;
        //delete(fx);
        switch (mode) {
        case MODE_DEFAULT:
            fx = fxDefault;
            break;
        case MODE_SPECIAL:
            //fx = new FXRotate(strip, TICK_INTERVAL);
            fx = fxSpecial;
            break;
        }
    }
}

void loop() {
    long now = millis();
    
    button.tick();

    if (digitalRead(PIN_BUTTON)==LOW) {
        lastPress = now;
    }
    
    if (now-lastPress < FX_DURATION) {
        setMode(MODE_SPECIAL);
    } else {
        setMode(MODE_DEFAULT);
    }

    fx->tick();

    delay(TICK_INTERVAL);
} // loop


void doubleclick() {
    if (fxSpecial == fxRotate) {
        fxSpecial = fxRainbow;
    } else {
        fxSpecial = fxRotate;
    }
    fx = fxSpecial;
}

void pressStart() {
    printf("pressStart() currently not used\n\r");
}

void pressStop() {
    printf("pressStop() currently not used\n\r");
}






