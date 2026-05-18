/*
  Day 1 Project 1: Potentiometer LED Dimmer
  Board: Arduino UNO
  Platform: Tinkercad Circuits

  Concept:
  - Read analog value from potentiometer
  - Convert it to PWM value
  - Control LED brightness
  - Print values on Serial Monitor
*/

const int potentiometerPin = A0;
const int ledPin = 11;   // PWM pin on Arduino UNO

int potentiometerValue = 0;
int ledBrightness = 0;

unsigned long lastPrintTime = 0;
const unsigned long printInterval = 300;

void setup() {
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Potentiometer LED Dimmer Started");
  Serial.println("--------------------------------");
}

void loop() {
  // Read analog value from potentiometer: 0 to 1023
  potentiometerValue = analogRead(potentiometerPin);

  // Convert 0-1023 range to 0-255 PWM range
  ledBrightness = map(potentiometerValue, 0, 1023, 0, 255);

  // Control LED brightness
  analogWrite(ledPin, ledBrightness);

  // Print values every 300 ms without slowing the main logic too much
  if (millis() - lastPrintTime >= printInterval) {
    lastPrintTime = millis();

    Serial.print("Potentiometer Value: ");
    Serial.print(potentiometerValue);

    Serial.print(" | LED Brightness: ");
    Serial.println(ledBrightness);
  }
}
