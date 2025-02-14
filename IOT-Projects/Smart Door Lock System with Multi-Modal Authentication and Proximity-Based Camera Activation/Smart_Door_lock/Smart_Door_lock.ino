#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define TRIGGER_PIN 12
#define ECHO_PIN 11

MFRC522 rfid(SS_PIN, RST_PIN);
SoftwareSerial mySerial(2, 3); // RX, TX
Servo myServo;

long duration;
int distance;
bool faceMatched = false;
bool thumbMatched = false;
bool rfidMatched = false;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); // For communication with Python
  SPI.begin();
  rfid.PCD_Init();
  myServo.attach(6);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize RFID and fingerprint sensors
  if (!rfid.PCD_Init()) {
    Serial.println("RFID sensor initialization failed.");
    while (1);
  }

  Serial.println("Sensors initialized.");
}

void loop() {
  // Check distance from ultrasonic sensor
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0344 / 2;

  if (distance < 20) { // Adjust the distance threshold as needed
    Serial.println("Object detected! Sending signal to open camera...");
    mySerial.write('1'); // Signal to open camera
  }

  // Read the signal from Python
  if (mySerial.available() > 0) {
    char received = mySerial.read();
    if (received == '2') {
      faceMatched = true;
    } else if (received == '0') {
      faceMatched = false;
    }
  }

  // RFID authentication
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String content = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      content.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
      content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    if (content == "03 A5 AE 1B") { // Example authorized UID
      Serial.println("RFID Authorized");
      rfidMatched = true;
    } else {
      rfidMatched = false;
    }
    rfid.PICC_HaltA();
  }

  // Thumb sensor authentication (example)
  if (thumbSensorAuthentication()) {
    Serial.println("Thumb sensor Authorized");
    thumbMatched = true;
  } else {
    thumbMatched = false;
  }

  // Check if any two authentications matched
  if ((faceMatched && rfidMatched) || (thumbMatched && rfidMatched) || (faceMatched && thumbMatched)) {
    Serial.println("Authentication successful. Unlocking door...");
    myServo.write(90); // Unlock position
    delay(5000); // Keep the door unlocked for 5 seconds
    myServo.write(0); // Lock position
  }
}

bool thumbSensorAuthentication() {
  // Placeholder for thumb sensor authentication logic
  // Replace with actual thumb sensor logic
  return false;
}
