int m1p = 2;
int m1n = 3;
int m2p = 4;
int m2n = 5;
int ena = 6;
int enb = 7;
int motorspeed = 200;

void setup() {
  // Set motor control pins as outputs
  pinMode(m1p, OUTPUT);
  pinMode(m1n, OUTPUT);
  pinMode(m2p, OUTPUT);
  pinMode(m2n, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  // Set initial motor speeds
  analogWrite(ena, motorspeed);
  analogWrite(enb, motorspeed);
}

void loop() {

    digitalWrite(m1p, HIGH);
    digitalWrite(m1n, LOW);
    digitalWrite(m2p, LOW);
    digitalWrite(m2n, HIGH);
    delay(5000);  // Move forward for 5 seconds

  
  

  // Stop motors after 4 iterations
  stopMotors();
  while (true); // Stop the loop
}

void stopMotors() {
  digitalWrite(m1p, LOW);
  digitalWrite(m1n, LOW);
  digitalWrite(m2p,LOW);
  digitalWrite(m2n,LOW);
}
