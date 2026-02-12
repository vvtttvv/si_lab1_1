#include <Arduino.h>
#include <stdio.h>
#include "Led.h"

void initSerialStdio();

Led led(13);

char command[20];

void setup() {
    initSerialStdio();

    printf("System ready.\n");
    printf("Type: led on | led off | led alert\n");
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
        else if (strcmp(command, "led alert") == 0) {
            led.blink_alert();
            printf("LED blinked for alert\n");
        }
        else {
            printf("Unknown command: %s\n", command);
        }
    }
}
