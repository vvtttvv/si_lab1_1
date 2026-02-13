#include <Arduino.h>
#include <stdio.h>

static int serial_putchar(char c, FILE* f) {
    Serial.write(c);
    return 0;
}

static int serial_getchar(FILE* f) {
    while (!Serial.available()) {
        // Wait for data
    }
    return Serial.read();
}

static FILE serial_stdout;
//serial_stdout is a global FILE structure that represents the serial output stream

void initSerialStdio() {
    Serial.begin(9600);
    //1 baud = 1 bit per second

    fdev_setup_stream(&serial_stdout, serial_putchar, serial_getchar, _FDEV_SETUP_RW);
    stdout = &serial_stdout;
    stdin = &serial_stdout;
}