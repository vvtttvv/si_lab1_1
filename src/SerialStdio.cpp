#include <Arduino.h>
#include <stdio.h>

static int serial_putchar(char c, FILE* f) {
    Serial.write(c);
    return 0;
}

static FILE serial_stdout;

void initSerialStdio() {
    Serial.begin(9600);

    fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_stdout;
}