// Define the pin connections
const int flameSensorPin = A0; // Connect the flame sensor to analog pin A0
const int buzzerPin = 8; // Connect the buzzer to digital pin 8

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read the analog value from the flame sensor
  int sensorValue = analogRead(flameSensorPin);
  
  // Print the sensor value (for debugging)
  Serial.println(sensorValue);
  
  // If flame is detected (adjust threshold value as needed)
  if (sensorValue > 100) {
    // Activate the buzzer
    digitalWrite(buzzerPin, HIGH);
    // Print a message indicating flame detection
    Serial.println("Flame detected!");
    // Add a delay to avoid rapid alarm triggering
    delay(1000);
  } else {
    // Turn off the buzzer if no flame is detected
    digitalWrite(buzzerPin, LOW);
  }
}
