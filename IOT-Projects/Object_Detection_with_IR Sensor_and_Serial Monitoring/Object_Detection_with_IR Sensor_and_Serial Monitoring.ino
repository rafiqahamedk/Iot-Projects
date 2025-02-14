// Define the pin for the IR sensor output
const int irSensorPin = 2;
void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  // Set the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
}
void loop() {
  // Read the state of the IR sensor
  int irSensorState = digitalRead(irSensorPin);
  // Print the sensor state (0 for no object detected, 1 for object detected)
  Serial.println(irSensorState);
  // Add a delay to prevent rapid serial output
  delay(100); // You can adjust this delay based on your needs
}
