void setup() {
  // Start serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // Check if data is available to read from the Bluetooth module
  if (Serial.available()) {
    // Read the incoming byte
    char incomingByte = Serial.read();

    // Print the incoming byte to the Serial Monitor (optional)
    Serial.print("Received: ");
    Serial.println(incomingByte);

    // Send the incoming byte back to the Bluetooth device (echo)
    Serial.print("Echo: ");
    Serial.println(incomingByte);
  }

  // You can also send data periodically
  static unsigned long lastSendTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - lastSendTime >= 1000) { // Send data every second
    Serial.println("Hello from Arduino!");
    lastSendTime = currentTime;
  }
}
