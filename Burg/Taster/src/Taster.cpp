#include <Arduino.h>
#include <Wire.h>

#include "ButtonManager.h"


const int numberOfButtons = 1;

// (Pin des Tasters (0-7), Pin des Lichts (34-48), (optional: Zeit, die der Taster deaktiviert ist in Sekunden))
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
    buttonArr[i].setCallback(CallLambda([slaveAddr, i] () {
      sendStart(slaveAddr[i]);
      return 1;
    }));
    ButtonManager::addButton(&buttonArr[i]);
  }

  ButtonManager::begin();
}


void loop() {}
