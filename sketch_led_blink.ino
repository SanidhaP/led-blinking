#include <Arduino.h>

const int ledPins[] = {2, 3, 4, 5, 6}; // Pins connected to LEDs
const int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);
unsigned long previousMillis[numLEDs];
const unsigned long intervals[] = {2000, 3000, 5000, 7000, 11000}; // Intervals for each LED

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
    previousMillis[i] = millis();
  }
}

void loop() {
  unsigned long currentMillis = millis();
  for (int i = 0; i < numLEDs; i++) {
    if (currentMillis - previousMillis[i] >= intervals[i]) {
      previousMillis[i] = currentMillis;
      toggleLED(ledPins[i]);
    }
  }
}

void toggleLED(int pin) {
  digitalWrite(pin, !digitalRead(pin)); // Toggle the LED state
}
