#include <Servo.h>

// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 8;

// Define servo pin
const int servoPin = 10;

// Define variables for distance measurement and servo control
long duration;
int distance;
Servo servo;

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin); // Attach servo to the specified pin
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the servo based on distance
  if (distance <= 10) {
    // Vehicle detected, raise the barrier
    raiseBarrier();
  } else {
    // No vehicle, lower the barrier
    lowerBarrier();
  }

  // Wait before taking the next measurement
  delay(500);
}

void raiseBarrier() {
  // Rotate the servo to raise the barrier (adjust angle as needed)
  servo.write(90); // 90 degrees is an example, adjust for your setup
  delay(1000); // Wait for the barrier to fully raise (adjust as needed)
}

void lowerBarrier() {
  // Rotate the servo to lower the barrier (adjust angle as needed)
  servo.write(0); // 0 degrees is an example, adjust for your setup
  delay(1000); // Wait for the barrier to fully lower (adjust as needed)
}
