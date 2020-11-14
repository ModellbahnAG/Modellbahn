#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"
#include <Wire.h>


class Button {
  private:
    byte address;     // Addresse des Slave
    byte inputPin;    // Pin des Tasters
    byte lightPin;    // Pin des Lichts
    int delayTime;    // Zeit, die der Taster deaktiviert ist (in Sekunden)

    unsigned long firsPress = 0;
    bool activated = true;

  public:
    Button(byte address, byte inputPin, byte lightPin, int delayTime = 60);

    void buttonPressed();

    void checkForTime();
};

#endif
