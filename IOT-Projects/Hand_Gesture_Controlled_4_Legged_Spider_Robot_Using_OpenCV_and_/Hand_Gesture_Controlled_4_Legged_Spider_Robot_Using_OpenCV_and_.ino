#include <Servo.h>

// Define the pins for the servos
#define HEAD_SERVO_PIN 13
#define LEG1_FRONT_PIN 4
#define LEG1_BACK_PIN 5
#define LEG2_FRONT_PIN 6
#define LEG2_BACK_PIN 7
#define LEG3_FRONT_PIN 8
#define LEG3_BACK_PIN 11
#define LEG4_FRONT_PIN 2
#define LEG4_BACK_PIN 3

// Create servo objects
Servo headServo;
Servo leg1FrontServo;
Servo leg1BackServo;
Servo leg2FrontServo;
Servo leg2BackServo;
Servo leg3FrontServo;
Servo leg3BackServo;
Servo leg4FrontServo;
Servo leg4BackServo;

void setup() {
  Serial.begin(9600);
  headServo.attach(HEAD_SERVO_PIN);
  leg1FrontServo.attach(LEG1_FRONT_PIN);
  leg1BackServo.attach(LEG1_BACK_PIN);
  leg2FrontServo.attach(LEG2_FRONT_PIN);
  leg2BackServo.attach(LEG2_BACK_PIN);
  leg3FrontServo.attach(LEG3_FRONT_PIN);
  leg3BackServo.attach(LEG3_BACK_PIN);
  leg4FrontServo.attach(LEG4_FRONT_PIN);
  leg4BackServo.attach(LEG4_BACK_PIN);
  
  // Set initial positions for the servos
  headServo.write(90); // Head servo facing forward
  leg1FrontServo.write(90);
  leg1BackServo.write(90);
  leg2FrontServo.write(90);
  leg2BackServo.write(90);
  leg3FrontServo.write(90);
  leg3BackServo.write(90);
  leg4FrontServo.write(90);
  leg4BackServo.write(90);
}

void moveForward() {
  // Example sequence for forward movement
  // Adjust the angles and delays according to your robot's needs
  leg1FrontServo.write(45);
  leg1BackServo.write(135);
  leg2FrontServo.write(45);
  leg2BackServo.write(135);
  leg3FrontServo.write(45);
  leg3BackServo.write(135);
  leg4FrontServo.write(45);
  leg4BackServo.write(135);
  delay(500); // Adjust the delay as needed

  leg1FrontServo.write(90);
  leg1BackServo.write(90);
  leg2FrontServo.write(90);
  leg2BackServo.write(90);
  leg3FrontServo.write(90);
  leg3BackServo.write(90);
  leg4FrontServo.write(90);
  leg4BackServo.write(90);
  delay(500); // Adjust the delay as needed
}

void stopMovement() {
  // Stop all servos by setting them to the initial position
  leg1FrontServo.write(90);
  leg1BackServo.write(90);
  leg2FrontServo.write(90);
  leg2BackServo.write(90);
  leg3FrontServo.write(90);
  leg3BackServo.write(90);
  leg4FrontServo.write(90);
  leg4BackServo.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'F') {
      moveForward();
    } else if (command == 'S') {
      stopMovement();
    }
  }
}
