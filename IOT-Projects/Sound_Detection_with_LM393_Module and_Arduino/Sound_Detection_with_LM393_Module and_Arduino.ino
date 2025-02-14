const int soundPin = 2;  // Digital pin connected to LM393 module

   void setup() {
       pinMode(soundPin, INPUT);
       Serial.begin(9600);
   }

   void loop() {
       int soundValue = digitalRead(soundPin);
       Serial.println(soundValue);  // Print sound value to serial monitor
       delay(1000);  // Delay for readability
   }
