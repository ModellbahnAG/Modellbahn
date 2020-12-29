#include <Arduino.h>
#include <Wire.h>
#include "Modellbahn.h"


//Pin für die LED
#define LEDPIN 11

//Anzahl der Angeschlossenen LEDs
#define NUMPIXELS 4

#define ADDRESS 1


int fire = 8;
int light = 9;

boolean shouldStartShow = false;

NeoPixel led(NUMPIXELS, LEDPIN);


void startShow() {
  unsigned long timeEnd = millis() + 30000;

  digitalWrite(fire, HIGH);
  analogWrite(light, 50);

  while (millis() < timeEnd) {
    LightEffects::torch(&led);
  }
  led.off();
  digitalWrite(fire, LOW);
  digitalWrite(light, LOW);
}

void receiveEvent(int howMany) {
  shouldStartShow = Wire.read();
}

void setup() {
  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);

  pinMode(light, OUTPUT);
  pinMode(fire, OUTPUT);

  receiveEvent(0);
}

void loop() {
  if (shouldStartShow) {
    startShow();
    shouldStartShow = false;
  }
}
