#include <NewPing.h>
#include <Servo.h>  // Include Servo library if needed for the motors

int m1p = 2;
int m1n = 3;
int m2p = 4;
int m2n = 5;
int ena = 6;
int enb = 7;
int motorspeed = 200;

void setup() {
  // Set motor control pins as outputs
  pinMode(m1p, OUTPUT);
  pinMode(m1n, OUTPUT);
  pinMode(m2p, OUTPUT);
  pinMode(m2n, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Set initial motor speeds
  analogWrite(ena, motorspeed);
  analogWrite(enb, motorspeed);

  // Initialize serial communication for Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  if (Serial.available()) {
    char command = Serial.read();

    // Execute commands based on received data
    if (command == 'F') {
      moveForward();
    } else if (command == 'B') {
      moveBackward();
    } else if (command == 'L') {
      turnLeft();
    } else if (command == 'R') {
      turnRight();
    } else if (command == 'S') {
      stopMotors();
    }
  }
}

void moveForward() {
  digitalWrite(m1p, HIGH);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, HIGH);
  digitalWrite(m2n, LOW);
}

void moveBackward() {
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, HIGH);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, HIGH);
}

void turnLeft() {
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, HIGH);
  digitalWrite(m2p, HIGH);
  digitalWrite(m2n, LOW);
}

void turnRight() {
  digitalWrite(m1p, HIGH);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, HIGH);
}

void stopMotors() {
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p, LOW);
  digitalWrite(m2n, LOW);
}
