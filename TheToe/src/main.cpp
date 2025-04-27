#include <Arduino.h>
#include <Servo.h>

// Define servo objects
Servo servo_tilt;
Servo servo_pan;
Servo servo_toe;

// Define pins
#define SERVO_TILT 2    // GP2
#define SERVO_PAN 3    // GP3
#define SERVO_TOE 4    // GP4
#define BUTTON1_PIN 10  // GP10 (for Servo 1 and Servo 2 action)

// Original servo angles
#define servo_tilt_ORIGINAL 93
#define servo_pan_ORIGINAL 90
#define servo_toe_ORIGINAL 90

// Movement offsets
#define servo_tilt_OFFSET -3
#define servo_pan_OFFSET 7
#define servo_toe_LEFT 80     // Left position for Servo 3
#define servo_toe_RIGHT 100   // Right position for Servo 3

// Hold time in milliseconds
#define HOLD_TIME 4000  // 2 seconds

void setup() {
    // Attach servos
    servo_tilt.attach(SERVO_TILT);
    servo_pan.attach(SERVO_PAN);
    servo_toe.attach(SERVO_TOE);

    // Move all servos to original positions
    servo_tilt.write(servo_tilt_ORIGINAL);
    servo_pan.write(servo_pan_ORIGINAL);
    servo_toe.write(servo_toe_ORIGINAL);

    // Setup button input with internal pull-up
    pinMode(BUTTON1_PIN, INPUT_PULLUP);
}

void loop() {
    // Check if BUTTON1 is pressed (for Servo 1 and 2)
    if (digitalRead(BUTTON1_PIN) == LOW) {
        // Move Servo 1 and 2
        servo_tilt.write(servo_tilt_ORIGINAL + servo_tilt_OFFSET);
        servo_pan.write(servo_pan_ORIGINAL + servo_pan_OFFSET);
        servo_toe.write(servo_toe_ORIGINAL + servo_toe_LEFT);

        delay(HOLD_TIME);

        // Return to original positions
        servo_tilt.write(servo_tilt_ORIGINAL);
        servo_pan.write(servo_pan_ORIGINAL);
        servo_toe.write(servo_toe_ORIGINAL);

        // Wait until button is released (debounce)
        while (digitalRead(BUTTON1_PIN) == LOW) {
            delay(10);
        }

    }

    // No code triggering Servo 3 yet
}
