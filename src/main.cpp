#include <Arduino.h>
#include <stdio.h>
#include "Led.h"

void initSerialStdio();

Led led(13);   // встроенный LED Arduino Uno

char command[20];

void setup() {
    initSerialStdio();

    printf("System ready.\n");
    printf("Type: led on | led off\n");
}

void loop() {
    if (Serial.available()) {
        int len = Serial.readBytesUntil('\n', command, sizeof(command) - 1);
        command[len] = '\0';

        if (strcmp(command, "led on") == 0) {
            led.on();
            printf("LED turned ON\n");
        }
        else if (strcmp(command, "led off") == 0) {
            led.off();
            printf("LED turned OFF\n");
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }
}
