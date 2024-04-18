const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9}; 
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Set all pins as outputs
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numLeds; i++) {
    // Turn on a pair of corresponding LEDs from each end
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLeds - i], HIGH);
    delay(500); // Wait for 500 milliseconds

    // Turn off the LEDs
    digitalWrite(ledPins[i], LOW);
    digitalWrite(ledPins[numLeds - i], LOW);
  }
}