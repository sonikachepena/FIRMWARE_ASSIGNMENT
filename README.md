# FIRMWARE_ASSIGNMENT
Here we Develop the code in Arduino to interface an LM35 temperature sensor  with an Arduino Uno and control the onboard LED based on temperature readings.

1. Interface the LM35 temperature sensor with an Arduino Uno.
2. When the temperature falls below 30 degrees Celsius, make the onboard LED
blink every 250 milliseconds.
3. If the temperature rises above 30 degrees Celsius, make the onboard LED blink
every 500 milliseconds.

Here we not supposed to use Millis(), delay() and micros() functions.

CODE_EXPLAINATION:

-> This code reads the analog voltage from the LM35 temperature sensor connected to pin A0 of the Arduino Uno. 

-> It then converts this voltage to temperature in degrees Celsius. Based on the temperature reading, it determines the interval for blinking the onboard LED (pin 13). 

-> The LED blinks at different intervals depending on whether the temperature is above or below 30°C. 

NOTE: The millis() function is used to track time intervals without causing delays in the program execution.

