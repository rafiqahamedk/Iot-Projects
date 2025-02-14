#include <Servo.h>

// Create Servo instance
Servo myServo;

// Servo control pin
const int servoPin = 9;

// Servo positions
const int posUp = 180;
const int posDown = 0;
const int posLeft = 90;
const int posRight = 45;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Attach the servo to the control pin
  myServo.attach(servoPin);

  // Initialize the servo to a default position
  myServo.write(posDown);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');

    if (command == "UP") {
      myServo.write(posUp);
    } else if (command == "DOWN") {
      myServo.write(posDown);
    } else if (command == "LEFT") {
      myServo.write(posLeft);
    } else if (command == "RIGHT") {
      myServo.write(posRight);
    }
  }
}
