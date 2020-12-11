#include <Arduino.h>
#include <Wire.h>

#include "Button.h"

/*
 * Taster können nur an folgende Pins angeschlossen werden: 2, 3, 18, 19, 20, 21
*/

const int numberOfButtons = 1;
// (Pin des Tasters (2, 3, 18, 19, 20, 21), Pin des Lichts, (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
Button buttonArr[numberOfButtons] = {Button(7, 34, 10)};   // Addressen müssen bei Master und Slave manuell eingestellt werden!!!
byte slaveAddr[numberOfButtons] = {0};


void sendStart(byte address) {
  Wire.begin(address);
  Wire.write(1);
  Wire.endTransmission();
}

void setup() {
  Wire.begin();

  Serial.begin(9600);

  for(int i = 0; i < numberOfButtons; i++) {
    buttonArr[i].setCallback(&sendStart, slaveAddr[i]);
  }
}

void loop() {
  for (int i = 0; i < numberOfButtons; i++) {     // durchläuft alle Taster, Anzahl der Taster muss oben angepasst werden!!!
    buttonArr[i].handleButton();       // Überprüft jeden Taster, ob er wieder aktiviert werden kann und ob er gedrückt wurde
  }
}
