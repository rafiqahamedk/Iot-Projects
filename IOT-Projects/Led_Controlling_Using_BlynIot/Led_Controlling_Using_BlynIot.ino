#define BLYNK_TEMPLATE_ID "TMPL3j478sxnQ"
#define BLYNK_TEMPLATE_NAME "RGB LED"
#define BLYNK_AUTH_TOKEN "iCiscru2ownuZRmh3CVLZVPLBnlYc6XA"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>  // Use <WiFi.h> for ESP32
#include <BlynkSimpleEsp8266.h>  // Use <BlynkSimpleEsp32.h> for ESP32

// Replace with your WiFi credentials
char ssid[] = "Rafi";
char pass[] = "12345678";

// Define pins for LEDs
const int ledPin1 = 5; // GPIO 4
const int ledPin2 = 4; // GPIO 0
const int ledPin3 = 0; // GPIO 2

void setup() {
  // Debug console
  Serial.begin(9600);

  // Set pin modes for LEDs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

// Blynk virtual pin handlers
BLYNK_WRITE(V1) {
  int led1State = param.asInt(); // Get the state of virtual pin V1
  digitalWrite(ledPin1, led1State);
}

BLYNK_WRITE(V2) {
  int led2State = param.asInt(); // Get the state of virtual pin V2
  digitalWrite(ledPin2, led2State);
}

BLYNK_WRITE(V3) {
  int led3State = param.asInt(); // Get the state of virtual pin V3
  digitalWrite(ledPin3, led3State);
}

void loop() {
  Blynk.run();
}
