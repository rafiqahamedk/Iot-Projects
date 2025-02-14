#define BLYNK_TEMPLATE_ID "TMPL3atK_i8GC"
#define BLYNK_TEMPLATE_NAME "SERVO"
#define BLYNK_AUTH_TOKEN "ED_cuOjLHpLvnhS-oY50Z30yU05eBoQ-"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>  // Use <WiFi.h> for ESP32
#include <BlynkSimpleEsp8266.h>  // Use <BlynkSimpleEsp32.h> for ESP32
#include <Servo.h>  // Include the Servo library

// Replace with your WiFi credentials
char ssid[] = "Batman";
char pass[] = "00000000";

// Define the servo pin
const int servoPin = 5; // GPIO 14 for ESP8266, change as per your board

Servo myServo; // Create a Servo object

void setup() {
  // Debug console
  Serial.begin(9600);

  // Attach the servo to the pin
  myServo.attach(servoPin);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Blynk virtual pin handler for controlling the servo
BLYNK_WRITE(V1) {
  int angle = param.asInt(); // Get the angle from virtual pin V1
  myServo.write(angle); // Set the servo to the desired angle
}

void loop() {
  Blynk.run();
}
