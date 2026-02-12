#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
public:
    Led(uint8_t pin);  
    void on();          
    void off();         

private:
    //used it because it will take less memory than usual int
    uint8_t _pin;      
};

#endif
