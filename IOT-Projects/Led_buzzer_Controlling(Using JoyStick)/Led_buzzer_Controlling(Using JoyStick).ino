const int LED_UP_PIN = 9;
const int LED_DOWN_PIN = 10;
const int LED_LEFT_PIN = 11;
const int LED_RIGHT_PIN = 12;
const int BUZZER_PIN = 13;

const int JOY_X_PIN = A0;
const int JOY_Y_PIN = A1;
const int JOY_CENTER_PIN = 2;

// Threshold values for detecting joystick movement
const int THRESHOLD = 500;

void setup() {
  pinMode(LED_UP_PIN, OUTPUT);
  pinMode(LED_DOWN_PIN, OUTPUT);
  pinMode(LED_LEFT_PIN, OUTPUT);
  pinMode(LED_RIGHT_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  pinMode(JOY_CENTER_PIN, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Read the joystick values
  int joyX = analogRead(JOY_X_PIN);
  int joyY = analogRead(JOY_Y_PIN);
  bool centerPressed = digitalRead(JOY_CENTER_PIN) == LOW;

  // Turn off all LEDs and buzzer initially
  digitalWrite(LED_UP_PIN, LOW);
  digitalWrite(LED_DOWN_PIN, LOW);
  digitalWrite(LED_LEFT_PIN, LOW);
  digitalWrite(LED_RIGHT_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Check joystick movement and turn on corresponding LED
  if (joyY > 1023 - THRESHOLD) {
    digitalWrite(LED_UP_PIN, HIGH);
  } else if (joyY < THRESHOLD) {
    digitalWrite(LED_DOWN_PIN, HIGH);
  }

  if (joyX > 1023 - THRESHOLD) {
    digitalWrite(LED_RIGHT_PIN, HIGH);
  } else if (joyX < THRESHOLD) {
    digitalWrite(LED_LEFT_PIN, HIGH);
  }

  // Check if the center button is pressed
  if (centerPressed) {
    digitalWrite(BUZZER_PIN, HIGH);
  }

  delay(100);  // Main loop delay
}
