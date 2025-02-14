#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 6
#define SERVO_PIN 7  // Servo control pin
#define LED_PIN 2  // LED control pin

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
Servo servo;  // Create servo instance

// Define the authorized UID
byte authorizedUid[] = {0x03, 0xA5, 0xAE, 0x1B};

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  SPI.begin();  // Initialize SPI communication
  mfrc522.PCD_Init();  // Initialize MFRC522 module
  servo.attach(SERVO_PIN);  // Attach servo to control pin
  pinMode(LED_PIN, OUTPUT);  // Initialize LED pin as output
}

void loop() {
  // Check for new RFID tags
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.print("Tag UID: ");
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
    mfrc522.PICC_HaltA();  // Halt PICC
    mfrc522.PCD_StopCrypto1();  // Stop encryption on PICC

    // Check if the scanned tag is authorized
    if (isAuthorized(mfrc522.uid.uidByte, mfrc522.uid.size)) {
      unlockDoor();
      digitalWrite(LED_PIN, HIGH);  // Turn on LED for access granted
      Serial.println("Access Granted");
      delay(2000);  // Delay for stability
    } else {
      digitalWrite(LED_PIN, LOW);  // Turn off LED for access denied
      Serial.println("Access Denied");
      delay(2000);  // Delay for stability
    }

    digitalWrite(LED_PIN, LOW);  // Turn off LED after access check
    Serial.println("Scan RFID Tag");
    delay(1000);  // Delay for stability
  }
}

// Helper function to print UID bytes
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

// Check if the scanned tag is authorized
bool isAuthorized(byte *tagUid, byte tagSize) {
  if (tagSize != sizeof(authorizedUid)) {
    return false;  // Tag size mismatch
  }
  for (byte i = 0; i < tagSize; i++) {
    if (tagUid[i] != authorizedUid[i]) {
      return false;  // Tag UID mismatch
    }
  }
  return true;  // Tag is authorized
}

// Unlock the door by rotating the servo motor
void unlockDoor() {
  servo.write(90);  // Rotate servo to unlock position (example)
  delay(1000);  // Keep door unlocked for 1 second
  servo.write(0);  // Rotate servo back to lock position
}
