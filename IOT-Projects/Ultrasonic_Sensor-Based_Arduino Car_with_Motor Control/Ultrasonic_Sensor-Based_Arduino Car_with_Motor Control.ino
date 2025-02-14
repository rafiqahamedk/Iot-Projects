#include <Servo.h>  // Include Servo library if needed for the motors

// Motor control pins
int m1p = 2;
int m1n = 3;
int m2p = 4;
int m2n = 5;
int ena = 6;
int enb = 7;
int motorspeed = 200;

// Ultrasonic sensor pins
const int trigPin = 8;
const int echoPin = 9;

void setup() {
  // Set motor control pins as outputs
  pinMode(m1p, OUTPUT);
  pinMode(m1n, OUTPUT);
  pinMode(m2p, OUTPUT);
  pinMode(m2n, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Set ultrasonic sensor pins as outputs/inputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set initial motor speeds
  analogWrite(ena, motorspeed);
  analogWrite(enb, motorspeed);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Debug print the distance
  Serial.print("Distance: ");
  Serial.println(distance);

  // Adjust movements based on distance
  if (distance > 50) {
    moveForward();  // Move forward if distance is greater than 50 cm
  } else{
    moveBackward();
    turnRight();

  }
} 


void moveForward() {
  Serial.println("Moving forward");
  digitalWrite(m1p, HIGH);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, HIGH);
  digitalWrite(m2n, LOW);
}

void moveBackward() {
  Serial.println("Moving backward");
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, HIGH);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, HIGH);
  delay(100);
}

void turnLeft() {
  Serial.println("Turning left");
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, HIGH);
  digitalWrite(m2p, HIGH);
  digitalWrite(m2n, LOW);
  delay(100);
}

void turnRight() {
  Serial.println("Turning right");
  digitalWrite(m1p, HIGH);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, HIGH);
  delay(100);
}

void stopMotors() {
  Serial.println("Stopping motors");
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, LOW);
}
