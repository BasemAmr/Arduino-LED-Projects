// Define the array of LED pins for the game
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// Define button pins for player input
const int buttonPin1 = 10; // Player 1 button
const int buttonPin2 = 11; // Player 2 button

// Game variables
int scorePlayer1 = 0;
int scorePlayer2 = 0;
int currentPosition = numLeds / 2;
int direction = 1; // 1 for right, -1 for left
int gameSpeed = 100; // Initial game speed in milliseconds

void setup() {
  Serial.begin(9600); // Start serial communication
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
  int stateButton1 = digitalRead(buttonPin1);
  int stateButton2 = digitalRead(buttonPin2);

  // Update direction based on button press
  if (stateButton1 == LOW) {
    direction = -1; // Move left
  }
  if (stateButton2 == LOW) {
    direction = 1; // Move right
  }

  // Move LED position
  digitalWrite(ledPins[currentPosition], LOW); // Turn off current LED
  currentPosition += direction;
  currentPosition = constrain(currentPosition, 0, numLeds - 1);
  digitalWrite(ledPins[currentPosition], HIGH); // Turn on new LED

  // Check for scoring
  if (currentPosition == 0 || currentPosition == numLeds - 1) {
    if (currentPosition == 0) scorePlayer1++;
    else scorePlayer2++;
    delay(200); // Flash delay
    gameSpeed = max(gameSpeed - 10, 60); // Increase speed
  }

  delay(gameSpeed); // Game speed delay

  // Print scores
  Serial.print("Player 1: ");
  Serial.print(scorePlayer1);
  Serial.print(" Player 2: ");
  Serial.println(scorePlayer2);
}