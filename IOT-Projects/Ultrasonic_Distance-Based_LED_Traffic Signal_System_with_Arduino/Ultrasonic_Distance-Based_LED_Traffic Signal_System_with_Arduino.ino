// Define pins for the ultrasonic sensor
const int trigPin = 9;
const int echoPin = 8;

// Define pins for the LEDs
const int redLED = 3;
const int yellowLED = 4;
const int greenLED = 5;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up the pins for the ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set up the pins for the LEDs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Initialize the LEDs to be off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, and calculate the distance in cm
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the LEDs based on the distance
  if (distance <= 10) { // If a vehicle is detected at a close distance
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);
  } else if (distance > 10 && distance <= 20) { // If a vehicle is at a moderate distance
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    delay(1000); // Keep the yellow LED on for a second
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  } else { // If no vehicle is detected
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  // Wait for a short period before measuring again
  delay(500);
}
