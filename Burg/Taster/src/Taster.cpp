#include <Arduino.h>
#include <Wire.h>

#include "Modellbahn.h"


#define NUM_BUTTON 5

// (Pin des Tasters (0-7), Pin des Lichts (gerade Zahlen 34-48), (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
Button buttonArr[NUM_BUTTON] = {Button(7, 34, 10),
                                Button(6, 36, 10),
                                Button(5, 38, 10),
                                Button(4, 40, 10),
                                Button(3, 42, 10)};   // Addressen müssen bei Master und Slave manuell eingestellt werden!!!
byte slaveAddr[NUM_BUTTON] = {0, 1, 2, 3, 4};


void sendStart(byte address) {
  Wire.beginTransmission(address);
  Wire.write(1);
  Wire.endTransmission();
  Serial.println(address);
}


void setup() {
  Wire.begin();
  Wire.setClock(10000);

  Serial.begin(9600);

  for(int i = 0; i < NUM_BUTTON; i++) {
    buttonArr[i].setCallback(CallLambda([i] () {
      Serial.println(i);
      sendStart(slaveAddr[i]);
      return 0;
    }));
    ButtonManager::addButton(&buttonArr[i]);
  }
}


void loop() {
  ButtonManager::handleButtons();
  delay(10);
}
