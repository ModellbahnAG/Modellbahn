#include <Arduino.h>
#include <Wire.h>

#include "Button.h"


// (Addresse des Slave, Pin des Tasters, Pin des Lichts, (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
Button taster[] = {Button(0, 53, 52)};   // Addressen müssen bei Master und Slave manuell eingestellt werden!!!

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 1; i++) {     // durchläuft alle Taster, Anzahl der Taster muss manuell angepasst werden!!!
    taster[i].handleButton();       // Überprüft jeden Taster, ob er wieder aktiviert werden kann und ob er gedrückt wurde
  }
}
