/*
  Day 1 Project: Simple IoT Memory Lock Game
  Board: Arduino UNO
  Platform: Tinkercad

  Game:
  - Arduino shows a random LED pattern.
  - Player repeats the pattern using buttons.
  - Correct pattern increases level.
  - Wrong pattern triggers buzzer alarm and restarts.

  Buttons use INPUT_PULLUP:
  Not pressed = HIGH
  Pressed     = LOW
*/

const int totalColors = 4;
const int maxLevel = 5;

// LED pins: Red, Yellow, Green, Blue
const int ledPins[totalColors] = {8, 9, 10, 11};

// Button pins: Red, Yellow, Green, Blue
const int buttonPins[totalColors] = {2, 3, 4, 5};

const int buzzerPin = 6;

// Pattern storage
int pattern[maxLevel];

// Game starts at level 1
int level = 1;

void setup() {
  Serial.begin(9600);

  // Set LED and button pins
  for (int i = 0; i < totalColors; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(buzzerPin, OUTPUT);

  randomSeed(analogRead(A0));

  Serial.println("================================");
  Serial.println(" Simple IoT Memory Lock Game");
  Serial.println("================================");
  Serial.println("Watch the LED pattern.");
  Serial.println("Repeat it using the buttons.");
  Serial.println("Wrong input = alarm + restart.");
  Serial.println();

  makeNewPattern();
}

void loop() {
  Serial.println("----------------------------");
  Serial.print("Level: ");
  Serial.println(level);
  Serial.println("Watch the pattern...");

  delay(1000);

  // Show pattern up to current level
  for (int i = 0; i < level; i++) {
    int color = pattern[i];

    blinkColor(color, 900);
    delay(450);
  }

  Serial.println("Now repeat the pattern.");

  // Check player input
  for (int i = 0; i < level; i++) {
    int expectedColor = pattern[i];
    int pressedColor = waitForButton();

    blinkColor(pressedColor, 300);

    Serial.print("Expected: ");
    Serial.print(expectedColor);
    Serial.print(" | Pressed: ");
    Serial.println(pressedColor);

    if (pressedColor != expectedColor) {
      wrongAnswer();
      return; // restart loop from level 1
    }
  }

  correctAnswer();
}

// Create random pattern
void makeNewPattern() {
  for (int i = 0; i < maxLevel; i++) {
    pattern[i] = random(0, totalColors);
  }
}

// Blink selected LED and play tone
void blinkColor(int color, int timeMs) {
  digitalWrite(ledPins[color], HIGH);
  tone(buzzerPin, 400 + color * 180);

  delay(timeMs);

  digitalWrite(ledPins[color], LOW);
  noTone(buzzerPin);
}

// Wait until one button is pressed
int waitForButton() {
  while (true) {
    for (int i = 0; i < totalColors; i++) {
      if (digitalRead(buttonPins[i]) == LOW) {
        delay(50); // debounce

        // Wait until button is released
        while (digitalRead(buttonPins[i]) == LOW) {
          delay(10);
        }

        return i;
      }
    }
  }
}

// When player enters correct pattern
void correctAnswer() {
  Serial.println("Correct!");
  successSound();

  level++;

  if (level > maxLevel) {
    Serial.println("ACCESS GRANTED!");
    Serial.println("You completed all levels.");
    celebration();

    level = 1;
    makeNewPattern();
  }

  delay(1200);
}

// When player enters wrong pattern
void wrongAnswer() {
  Serial.println("Wrong!");
  Serial.println("ACCESS DENIED! Restarting from Level 1.");

  alarm();

  level = 1;
  makeNewPattern();

  delay(1500);
}

// Simple success sound
void successSound() {
  tone(buzzerPin, 700);
  delay(200);
  tone(buzzerPin, 1000);
  delay(250);
  noTone(buzzerPin);
}

// Alarm effect
void alarm() {
  for (int i = 0; i < 4; i++) {
    // Turn all LEDs ON
    for (int j = 0; j < totalColors; j++) {
      digitalWrite(ledPins[j], HIGH);
    }

    tone(buzzerPin, 180);
    delay(250);

    // Turn all LEDs OFF
    for (int j = 0; j < totalColors; j++) {
      digitalWrite(ledPins[j], LOW);
    }

    noTone(buzzerPin);
    delay(250);
  }
}

// Winning effect
void celebration() {
  for (int round = 0; round < 3; round++) {
    for (int i = 0; i < totalColors; i++) {
      blinkColor(i, 200);
      delay(100);
    }
  }
}
