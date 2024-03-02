const int sensorPin = A0;  // LM35 sensor connected to analog pin A0
const int ledPin = 13;     // Onboard LED connected to digital pin 13

unsigned long previousMillis = 0;
const long intervalLowTemp = 250;   // Blink interval for low temperature (in milliseconds)
const long intervalHighTemp = 500;  // Blink interval for high temperature (in milliseconds)

float temperature;  // Variable to store temperature reading

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time
  
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(sensorPin);
  temperature = (sensorValue * 5.0 * 100.0) / 1024.0; // Convert sensor value to temperature in Celsius
  
  // Check temperature and control LED blinking
  if (temperature < 30.0) {
    if (currentMillis - previousMillis >= intervalLowTemp) {
      previousMillis = currentMillis;  // Save the last time the LED blinked
      digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle LED state
    }
  } else {
    if (currentMillis - previousMillis >= intervalHighTemp) {
      previousMillis = currentMillis;  // Save the last time the LED blinked
      digitalWrite(ledPin, !digitalRead(ledPin));  // Toggle LED state
    }
  }
  
  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
}
