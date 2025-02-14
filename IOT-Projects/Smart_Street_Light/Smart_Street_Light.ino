// Define the pin numbers
const int ldrPin = A0;  // LDR connected to analog pin A0
const int ledPin = 13;  // LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  Serial.begin(9600);       // Initialize serial communication
}

void loop() {
  int lightLevel = analogRead(ldrPin);  // Read the light level from the LDR
  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);  // Print the light level to the serial monitor
  
  // Set a threshold value for turning on/off the LED
  int threshold = 500;  // Adjust this value based on your environment
  
  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED if light level is below threshold
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED if light level is above threshold
  }
  
  delay(100);  // Delay for stability
}
