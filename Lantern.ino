#include <OneButton.h>
#include <Adafruit_NeoPixel.h>

#include "myprintf.h"
#include "FXCandle.h"
#include "FXRotate.h"

#define PIN_BUTTON 2
#define PIN_LEDS   3
#define TICK_INTERVAL 5


OneButton button(2, true);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN_LEDS, NEO_GRB + NEO_KHZ800);

Effect *fx;

void setup() {

    button.attachDoubleClick(doubleclick);
    button.attachLongPressStart(pressStart);
    button.attachLongPressStop(pressStop);
    
    strip.begin();
    
    fx = new FXCandle(strip, TICK_INTERVAL);

    Serial.begin(57600);
    printf_begin();
    printf("Fancy Lantern\n\r");
}


void loop() {
    button.tick();
    fx->tick();

    delay(TICK_INTERVAL);
} // loop


void doubleclick() {
    static int m = LOW;
    // reverse the LED 
    m = !m;
    digitalWrite(13, m);
} // doubleclick

void pressStart() {
    printf("pressStart()\n\r");
    delete(fx);
    fx = new FXRotate(strip, TICK_INTERVAL); 
}

void pressStop() {
    printf("pressStop()\n\r");
    delete(fx);
    fx = new FXCandle(strip, TICK_INTERVAL); 
}


