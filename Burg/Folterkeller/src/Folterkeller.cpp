#include <Arduino.h>
#include <Wire.h>
#include "Modellbahn.h"

#define ADDRESS 1

//Pin für die LED
#define LEDPIN 11
//Anzahl der Angeschlossenen LEDs
#define NUMPIXELS 4

#define FIRE_PIN 8
#define LIGHT_PIN 9

// Zeit, die die Show dauern soll
#define SHOW_DURATION 10

boolean shouldStartShow = false;

NeoPixel led(NUMPIXELS, LEDPIN);


void startShow() {
  int duration = 10;

  digitalWrite(FIRE_PIN, HIGH);
  analogWrite(LIGHT_PIN, 50);

  led.torch(duration);

  led.off();
  digitalWrite(FIRE_PIN, LOW);
  digitalWrite(LIGHT_PIN, LOW);
}

/* Setze shouldStartShow auf true wenn eine Signal vom Taster Arduino ankommt
*
* Die eigentlich Explosion kann nicht in dieser Funktion ausgeführt werden, da
* es bei Interrupt Funktionen Probleme mit delay gibt.
*/
void receiveEvent(int howMany) {
  shouldStartShow = Wire.read();
}

void setup() {
  Serial.begin(9600);
  pinMode(LIGHT_PIN, OUTPUT);
  pinMode(FIRE_PIN, OUTPUT);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);
}

void loop() {
  if (shouldStartShow) {
    startShow();
    shouldStartShow = false;
  }
}
