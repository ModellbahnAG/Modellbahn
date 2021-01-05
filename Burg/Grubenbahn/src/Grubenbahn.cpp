#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 2
#define TRAIN_PIN 12
#define LED_PIN 11

boolean shouldStartTrain = false;

int helligkeitLed = 50;

void startTrain() {
  digitalWrite(TRAIN_PIN, HIGH);
  delay(5000);
  digitalWrite(TRAIN_PIN, LOW);
}

void receiveEvent(int howMany) {
  shouldStartTrain = Wire.read();
}

void setup() {
  pinMode(TRAIN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);

  randomSeed(analogRead(A0));

  analogWrite(LED_PIN, helligkeitLed);
}

void loop() {
  if (random(1, 10000) == 1) {
    analogWrite(LED_PIN, 0);
    delay(5);
    analogWrite(LED_PIN, helligkeitLed);
  }

  if (shouldStartTrain) {
    startTrain();
    shouldStartTrain = false;
  }
}
