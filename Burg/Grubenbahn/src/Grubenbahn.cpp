#include <Arduino.h>
#include <Wire.h>

#define ADDRESS 2

int bahn = 13;
int led = 11;

boolean shouldStartTrain = false;

int helligkeitLed = 50;

void startTrain() {
  digitalWrite(bahn, HIGH);
  delay(5000);
  digitalWrite(bahn, LOW);
}

void receiveEvent(int howMany) {
  shouldStartTrain = Wire.read();
}

void setup() {
  pinMode(bahn, OUTPUT);
  pinMode(led, OUTPUT);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);

  randomSeed(analogRead(A0));

  analogWrite(led, helligkeitLed);
}

void loop() {
  int zufall = random(1, 10000);

  if (zufall == 1) {
    analogWrite(led, 0);
    delay(5);
    analogWrite(led, helligkeitLed);
  }

  if (shouldStartTrain) {
    startTrain();
  }
}
