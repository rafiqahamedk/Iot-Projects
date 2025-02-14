#include <DHT.h>
#include <DHT_U.h>

#include <dht.h>  // include the DHT library
#include <LiquidCrystal.h> // include the LCD library

#define DHTPIN 2  // Define the pin to which the DHT11 sensor is connected
#define DHTTYPE DHT11 // Define the type of the DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

// Initialize the LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 1);

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  // Initialize the LCD:
  lcd.begin(16, 2);
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read humidity
  float humidity = dht.readHumidity();
  // Read temperature as Celsius
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");

  // Display values on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000); // Delay for 2 seconds
}
