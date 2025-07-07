#include <Arduino.h>

const int relay1Pin = 15;
const int relay2Pin = 27;

unsigned long previousMillis = 0;
unsigned long interval = 0;

bool relay1State = true;
bool relay2State = false;

void setup() {
  Serial.begin(115200);

  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  digitalWrite(relay1Pin, LOW);  // ON
  digitalWrite(relay2Pin, HIGH); // OFF

  randomSeed(analogRead(0)); // Add this line for better randomness

  interval = random(1000, 5000); // Should now work
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    relay1State = !relay1State;
    relay2State = !relay2State;

    digitalWrite(relay1Pin, relay1State ? LOW : HIGH);
    digitalWrite(relay2Pin, relay2State ? LOW : HIGH);

    Serial.print("Swapped. Next switch in ");
    interval = random(1000, 5000);
    Serial.print(interval / 1000);
    Serial.println(" seconds");
  }
}