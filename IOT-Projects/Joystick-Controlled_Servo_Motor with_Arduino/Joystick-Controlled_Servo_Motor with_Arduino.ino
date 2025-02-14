#include <Servo.h>

// Define the pins for the joystick and servo
const int joyXPin = A0; // Joystick X-axis connected to analog pin A0
const int servoPin = 9; // Servo signal pin connected to digital pin 9

// Define variables to store joystick and servo values
int joyXValue = 0;
int servoAngle = 80; // Initial position for the servo

// Define the servo object
Servo myServo;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Attach the servo to its pin
  myServo.attach(servoPin);
}

void loop() {
  // Read the joystick value
  joyXValue = analogRead(joyXPin);

  // Map joystick value to servo range (0-180)
  servoAngle = map(joyXValue, 0, 1023, 45,160);

  // Control the servo with joystick
  myServo.write(servoAngle);

  // Print joystick value and servo angle to serial monitor
  Serial.print("X-Axis: ");
  Serial.print(joyXValue);
  Serial.print(" - Servo Angle: ");
  Serial.println(servoAngle);

  // Delay for stability
  delay(100);
}
