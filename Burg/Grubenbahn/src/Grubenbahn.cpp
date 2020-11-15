#include <Arduino.h>
#include <Wire.h>

byte address = 3;

int bahn = 13;
int led = 11;

int helligkeitLed = 50;

void receiveEvent(int howMany) {
  digitalWrite(bahn, HIGH);
  delay(5000);
  digitalWrite(bahn, LOW);
}

void setup() {
  pinMode(bahn, OUTPUT);
  pinMode(led, OUTPUT);

  Wire.begin(address);
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
}
