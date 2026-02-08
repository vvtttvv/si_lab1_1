#include "Led.h"

Led::Led(uint8_t pin) : _pin(pin) {
    pinMode(_pin, OUTPUT);
    off();
}

void Led::on() {
    digitalWrite(_pin, HIGH);
}

void Led::off() {
    digitalWrite(_pin, LOW);
}
