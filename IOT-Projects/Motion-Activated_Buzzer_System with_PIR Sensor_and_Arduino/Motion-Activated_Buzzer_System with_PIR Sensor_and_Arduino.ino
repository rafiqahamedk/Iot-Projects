// Define the pin connected to the PIR sensor
const int pirSensorPin = 2; // Adjust pin number as needed
// Define the pin connected to the buzzer
const int buzzerPin = 3; // Adjust pin number as needed

// Define the threshold value
const int motionThreshold = 1; // Adjust this value as needed
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the PIR sensor pin as an input
  pinMode(pirSensorPin, INPUT);
  
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}
void loop() {
  // Read the digital value from the PIR sensor
  int motionValue = digitalRead(pirSensorPin);
  // Print the motion value to the serial monitor
  Serial.print("Motion Value: ");
  Serial.println(motionValue);

  // Check if the motion value exceeds the threshold
  if (motionValue > motionThreshold) {
    // If motion is detected, trigger the buzzer
    Serial.println("Motion Detected!");
    tone(buzzerPin, 1000); // Play a tone at 1000 Hz
    delay(1000); // Buzz for 1 second
    noTone(buzzerPin); // Stop the buzzer
  }
  // Add a delay to prevent rapid triggering
  delay(1000);
}
