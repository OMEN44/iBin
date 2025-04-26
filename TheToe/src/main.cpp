#include<Arduino.h>
#include<stdio.h>
#include <Servo.h>

Servo servo;

void setup() {
    servo.attach(4);
}

void loop() {
    for (int i = 0; i < 90; i++) {
        servo.write(i);
        delay(50);
    }
    for (int i = 90; i > 0; i--) {
        servo.write(i);
        delay(50);
    }
    
    
}
