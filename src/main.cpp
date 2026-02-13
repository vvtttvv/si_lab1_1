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
    fgets(command, sizeof(command), stdin);
    // Remove both \r and \n
    command[strcspn(command, "\r\n")] = '\0';
    
    for (int i = 0; command[i]; i++) {
        command[i] = tolower(command[i]);
    }

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
