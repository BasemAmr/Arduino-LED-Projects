const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; // LED pins
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Initialize all LEDs to OFF state
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Start from the center and diverge towards the ends
  for (int i = 0; i < numLeds / 2; i++) {
    digitalWrite(ledPins[numLeds / 2 - i - 1], HIGH); // Turn on left-center LED
    digitalWrite(ledPins[numLeds / 2 + i], HIGH);     // Turn on right-center LED
    delay(500); // Wait for 500 milliseconds

    // Turn off the LEDs after the delay
    digitalWrite(ledPins[numLeds / 2 - i - 1], LOW);
    digitalWrite(ledPins[numLeds / 2 + i], LOW);
  }
}