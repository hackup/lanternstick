#include <limits.h>
#include <OneButton.h>
#include <Adafruit_NeoPixel.h>

#include "myprintf.h"
#include "FXCandle.h"
#include "FXRotate.h"

#define PIN_BUTTON 2
#define PIN_LEDS   3
#define TICK_INTERVAL 10
#define FX_DURATION 3000

#define MODE_CANDLE 0
#define MODE_ROTATE 1

OneButton button(2, true);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN_LEDS, NEO_GRB + NEO_KHZ800);

Effect *fx;
uint8_t mode;
long lastPress;

void setup() {

    button.attachDoubleClick(doubleclick);
    button.attachLongPressStart(pressStart);
    button.attachLongPressStop(pressStop);

    strip.begin();

    fx = new FXCandle(strip, TICK_INTERVAL);
    mode = MODE_CANDLE;
    lastPress = -;

    Serial.begin(57600);
    printf_begin();
    printf("Fancy Lantern\n\r");
}

void setMode(uint8_t aMode) {
    if (mode!=aMode) {
        mode = aMode;
        delete(fx);
        switch (mode) {
        case MODE_CANDLE:
            fx = new FXCandle(strip, TICK_INTERVAL);
            break;
        case MODE_ROTATE:
            fx = new FXRotate(strip, TICK_INTERVAL);
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
        setMode(MODE_ROTATE);
    } else {
        setMode(MODE_CANDLE);
    }

    fx->tick();

    delay(TICK_INTERVAL);
} // loop


void doubleclick() {
    static int m = LOW;
    // reverse the LED 
    m = !m;
    digitalWrite(13, m);
}

void pressStart() {
    printf("pressStart() currently not used\n\r");
}

void pressStop() {
    printf("pressStop() currently not used\n\r");
}






