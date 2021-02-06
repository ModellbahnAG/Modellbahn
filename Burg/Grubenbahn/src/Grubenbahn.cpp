#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 2
#define TRAIN_PIN 12
#define LED_PIN 11

// Zeit die die Lampen beim Flackern aus sind
#define FLICKERING_TIME 5
// Helligkeit der Beleuchtung
#define LIGHTING_BRIGHTNESS 50

boolean shouldStartTrain = false;

void startTrain() {
  digitalWrite(TRAIN_PIN, HIGH);
  delay(5000);
  digitalWrite(TRAIN_PIN, LOW);
}

/* Setze shouldStartTrain auf true wenn eine Signal vom Taster Arduino ankommt
*
* Die eigentlich Explosion kann nicht in dieser Funktion ausgeführt werden, da
* es bei Interrupt Funktionen Probleme mit delay gibt.
*/
void receiveEvent(int howMany) {
  shouldStartTrain = Wire.read();
}

void setup() {
  pinMode(TRAIN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);

  randomSeed(analogRead(A0));

  analogWrite(LED_PIN, LIGHTING_BRIGHTNESS);
}

void loop() {
  // lasse die Beleuchtung zufällig flackern
  if (random(1, 10000) == 1) {
    analogWrite(LED_PIN, 0);
    delay(FLICKERING_TIME);
    analogWrite(LED_PIN, LIGHTING_BRIGHTNESS);
  }

  if (shouldStartTrain) {
    startTrain();
    shouldStartTrain = false;
  }
}
