#include <Arduino.h>
#include <Wire.h>

#include "Button.h"


/*
 * Taster können nur an folgende Pins angeschlossen werden: 2, 3, 18, 19, 20, 21
*/

// (Addresse des Slave, Pin des Tasters (2, 3, 18, 19, 20, 21), Pin des Lichts, (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
Button taster[] = {Button(0, 2, 52)};   // Addressen müssen bei Master und Slave manuell eingestellt werden!!!

void setup() {
  Serial.begin(9600);

  Wire.begin();
}

void loop() {
  for (int i = 0; i < 1; i++) {     // durchläuft alle Taster, Anzahl der Taster muss manuell angepasst werden!!!
    taster[i].checkForTime();       // Überprüft jeden Taster, ob er wieder aktiviert werden kann
  }
}
