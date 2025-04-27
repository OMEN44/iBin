#include <Arduino.h>
#include <Servo.h>

// Define servo objects
Servo servo1;
Servo servo2;
Servo servo3;

// Define pins
#define SERVO1_PIN 2    // GP2
#define SERVO2_PIN 3    // GP3
#define SERVO3_PIN 4    // GP4
#define BUTTON1_PIN 10  // GP10 (for Servo 1 and Servo 2 action)

// Original servo angles
#define SERVO1_ORIGINAL 93
#define SERVO2_ORIGINAL 90
#define SERVO3_ORIGINAL 90

// Movement offsets
#define SERVO1_OFFSET -3
#define SERVO2_OFFSET 7
#define SERVO3_LEFT 80     // Left position for Servo 3
#define SERVO3_RIGHT 100   // Right position for Servo 3

// Hold time in milliseconds
#define HOLD_TIME 4000  // 2 seconds

void moveServo3Left() {
    servo3.write(SERVO3_LEFT);
}

void moveServo3Right() {
    servo3.write(SERVO3_RIGHT);
}

void moveServo3Center() {
    servo3.write(SERVO3_ORIGINAL);
}

void setup() {
    // Attach servos
    servo1.attach(SERVO1_PIN);
    servo2.attach(SERVO2_PIN);
    servo3.attach(SERVO3_PIN);

    // Move all servos to original positions
    servo1.write(SERVO1_ORIGINAL);
    servo2.write(SERVO2_ORIGINAL);
    servo3.write(SERVO3_ORIGINAL);

    // Setup button input with internal pull-up
    pinMode(BUTTON1_PIN, INPUT_PULLUP);
}

void loop() {
    // Check if BUTTON1 is pressed (for Servo 1 and 2)
    if (digitalRead(BUTTON1_PIN) == LOW) {
        // Move Servo 1 and 2
        servo1.write(SERVO1_ORIGINAL + SERVO1_OFFSET);
        servo2.write(SERVO2_ORIGINAL + SERVO2_OFFSET);

        delay(HOLD_TIME);

        // Return to original positions
        servo1.write(SERVO1_ORIGINAL);
        servo2.write(SERVO2_ORIGINAL);

        // Wait until button is released (debounce)
        while (digitalRead(BUTTON1_PIN) == LOW) {
            delay(10);
        }
    }

    // No code triggering Servo 3 yet
}
