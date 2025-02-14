#include <Servo.h>
#include <NewPing.h>

// Define the pins for the ultrasonic sensor
#define TRIGGER_PIN  10
#define ECHO_PIN     9
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters)

// Define servo pins
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

// Create ultrasonic sensor object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Function to initialize servos
void setupServos() {
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
  leg1FrontServo.write(180);
  leg1BackServo.write(90);
  leg2FrontServo.write(180);
  leg2BackServo.write(90);
  leg3FrontServo.write(180);
  leg3BackServo.write(90);
  leg4FrontServo.write(180);
  leg4BackServo.write(90);
}

// Function to move the spider forward
void moveForward() {
  // Add your forward walking sequence here
  // Example sequence (simplified for illustration purposes):
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

// Function to turn the spider left
void turnLeft() {
  leg1FrontServo.write(135);
  leg1BackServo.write(45);
  leg2FrontServo.write(45);
  leg2BackServo.write(135);
  leg3FrontServo.write(135);
  leg3BackServo.write(45);
  leg4FrontServo.write(45);
  leg4BackServo.write(135);
  delay(500); // Adjust the delay as needed
}

// Function to turn the spider right
void turnRight() {
  leg1FrontServo.write(45);
  leg1BackServo.write(135);
  leg2FrontServo.write(135);
  leg2BackServo.write(45);
  leg3FrontServo.write(45);
  leg3BackServo.write(135);
  leg4FrontServo.write(135);
  leg4BackServo.write(45);
  delay(500); // Adjust the delay as needed
}

// Function to avoid obstacles
void avoidObstacle() {
  // Rotate the head servo to scan the surroundings
  headServo.write(0);
  delay(500);
  int distanceLeft = sonar.ping_cm();
  
  headServo.write(180);
  delay(500);
  int distanceRight = sonar.ping_cm();
  
  headServo.write(90); // Reset head position
  delay(500);
  
  if (distanceLeft > distanceRight) {
    turnLeft();
  } else {
    turnRight();
  }
}

void setup() {
  Serial.begin(9600);
  setupServos();
}

void loop() {
  int distance = sonar.ping_cm();
  if (distance > 0 && distance < 30) { // If an obstacle is detected within 30 cm
    avoidObstacle();
  } else {
    moveForward();
  }
}
