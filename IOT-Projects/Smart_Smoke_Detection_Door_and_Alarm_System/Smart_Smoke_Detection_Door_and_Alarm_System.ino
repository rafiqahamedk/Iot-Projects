#include <Servo.h>

const int smokeSensorPin = A0;  // Smoke sensor connected to A0
const int ledPin = 11;          // LED connected to digital pin 11
const int buzzerPin = 10;       // Buzzer connected to digital pin 10
const int servoPin = 6;         // Servo connected to digital pin 6
const int smokeThreshold = 300; // Threshold value for smoke detection
Servo myServo;                  // Create a Servo object

void setup() {
  pinMode(smokeSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  myServo.attach(servoPin);     // Attach the servo to pin 6
  myServo.write(0);             // Initial position of the servo (door closed)
  
  Serial.begin(9600);           // Initialize serial communication
}

void loop() {
  int smokeLevel = analogRead(smokeSensorPin);  // Read the smoke sensor value

  Serial.print("Smoke Level: ");
  Serial.println(smokeLevel);

  if (smokeLevel > smokeThreshold) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    myServo.write(90);           // Rotate the servo to open the door
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    myServo.write(0);            // Rotate the servo to close the door
  }

  delay(500);  // Wait for 0.5 seconds before checking again
}
