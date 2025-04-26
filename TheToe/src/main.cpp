#include<Arduino.h>
#include<stdio.h>
#include <Servo.h>

Servo servo;

void setup() {
    servo.attach(4);
}

void loop() {
    delay(50);
    for (int i = 0; i < 180; i++) {
        servo.write(i);
    }
    for (int i = 180; i > 0; i--) {
        servo.write(i);
    }
    
    
}
