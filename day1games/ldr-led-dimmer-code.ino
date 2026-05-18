const int ldrPin = A0;
const int lampLedPin = 9;

int lightValue = 0;
const int darknessThreshold = 500;

void setup() {
  pinMode(lampLedPin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Smart Night Lamp Started");
}

void loop() {
  lightValue = analogRead(ldrPin);

  Serial.print("Light Value: ");
  Serial.print(lightValue);

  if (lightValue < darknessThreshold) {
    digitalWrite(lampLedPin, HIGH);
    Serial.println(" | DARK - Lamp ON");
  } else {
    digitalWrite(lampLedPin, LOW);
    Serial.println(" | BRIGHT - Lamp OFF");
  }

  delay(500);
}
