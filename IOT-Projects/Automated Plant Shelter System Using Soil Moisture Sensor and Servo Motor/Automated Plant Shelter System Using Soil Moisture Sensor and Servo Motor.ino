#include <Servo.h>

#define HUMIDITY_THRESHOLD 700 // Adjust this value according to your sensor and soil moisture requirements

const int humidityPin = A0; // Connect the humidity sensor to analog pin A0
const int servoPin = 9; // Connect the servo motor signal wire to digital pin 9

Servo servo;

void setup() {
  pinMode(humidityPin, INPUT);
  servo.attach(servoPin);
}

void loop() {
  int humidityValue = analogRead(humidityPin);

  if (humidityValue > HUMIDITY_THRESHOLD) {
    // Soil is dry, activate servo to open shelter
    openShelter();
  } else {
    // Soil is moist, deactivate servo to close shelter
    closeShelter();
  }

  delay(1000); // Adjust delay as needed
}

void openShelter() {
  // Rotate servo to open shelter position
  servo.write(0); // Adjust angle as needed
}

void closeShelter() {
  // Rotate servo to close shelter position
  servo.write(90); // Adjust angle as needed
}
