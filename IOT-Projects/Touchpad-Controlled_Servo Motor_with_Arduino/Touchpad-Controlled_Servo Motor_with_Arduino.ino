#include <Servo.h>

Servo myServo;  // Create a Servo object

const int touchPin = 2;  // Pin where the touchpad is connected
const int servoPin = 9;  // Pin where the servo motor is connected

void setup() {
  Serial.begin(9600);  // Start the serial communication at 9600 baud rate
  pinMode(touchPin, INPUT);
  myServo.attach(servoPin);  // Attach the servo to the specified pin
  myServo.write(0);  // Initialize the servo to 0 degrees
  Serial.println("Servo initialized at 0 degrees.");
}

void loop() {
  int touchState = digitalRead(touchPin);  // Read the state of the touchpad

  if (touchState == HIGH) {
    myServo.write(180);  // Move the servo to 90 degrees when touched
    Serial.println("Touchpad touched. Servo moved to 90 degrees.");
  } else {
    myServo.write(0);  // Move the servo to 0 degrees when not touched
    Serial.println("Touchpad not touched. Servo moved to 0 degrees.");
  }

  delay(50);  // Add a small delay to debounce the touchpad
}
