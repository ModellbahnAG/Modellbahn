#include <Arduino.h>
#include <Wire.h>

#include "Modellbahn.h"


#define NUM_BUTTON 5

// (Pin des Tasters (0-7), Pin des Lichts (gerade Zahlen 34-48), (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
Button buttonArr[NUM_BUTTON] = {Button(7, 34),
                                    Button(6, 36),
                                    Button(5, 38),
                                    Button(4, 40),
                                    Button(3, 42)};   // Addressen müssen bei Master und Slave manuell eingestellt werden!!!
byte slaveAddr[NUM_BUTTON] = {0, 1, 2, 3, 4};


void sendStart(byte address) {
  Wire.begin(address);
  Wire.write(1);
  Wire.endTransmission();
}


void setup() {
  Wire.begin();

  Serial.begin(9600);

  for(int i = 0; i < NUM_BUTTON; i++) {
    buttonArr[i].setCallback(CallLambda([i] () {
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
