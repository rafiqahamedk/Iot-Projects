#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN   5 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define SERVO_1_PIN 9    // Pin for first servo
#define SERVO_2_PIN 10   // Pin for second servo
#define SERVO_3_PIN 11   // Pin for third servo

#define LED_PIN_1 4      // Pin for first LED
#define LED_PIN_2 3      // Pin for second LED
#define LED_PIN_3 2      // Pin for third LED

Servo servo1;
Servo servo2;
Servo servo3;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);
  
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}

void loop() {
  delay(50);
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).

  // Convert ping time to distance in cm
  unsigned int distance = uS / US_ROUNDTRIP_CM;

  if (distance <= 20) {  // If the distance is less than or equal to 20cm
    servo1.write(90);   // Rotate first servo to 90 degrees
    delay(1000);
    servo2.write(0);    // Rotate second servo to 0 degrees
    delay(1000);
    servo3.write(180);  // Rotate third servo to 180 degrees

    digitalWrite(LED_PIN_1, HIGH); // Turn on first LED
    digitalWrite(LED_PIN_2, LOW);  // Turn off second LED
    digitalWrite(LED_PIN_3, HIGH); // Turn on third LED
  } else {
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);
    
    digitalWrite(LED_PIN_1, HIGH); // Turn on first LED
    digitalWrite(LED_PIN_2, HIGH); // Turn on second LED
    digitalWrite(LED_PIN_3, HIGH); // Turn on third LED
  }
}
