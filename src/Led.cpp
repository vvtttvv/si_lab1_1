#include "Led.h"

Led::Led(uint8_t pin) : _pin(pin) {
    pinMode(_pin, OUTPUT); //set the pin as output, so we can control the LED with on() and off()
    off();
}

void Led::on() {
    digitalWrite(_pin, HIGH);
}

void Led::off() {
    digitalWrite(_pin, LOW);
}

void Led::blink_alert() {
    for (int i = 0; i < 3; i++) {
        on();
        delay(200);
        off();
        delay(200);
    }
}