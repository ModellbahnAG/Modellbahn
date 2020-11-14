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

    unsigned long lastPress = 0;   // Zeit, zu der der Taster zum letzten Mal gedrückt wurde
    bool activated = true;

  public:
    Button(byte address, byte inputPin, byte lightPin, int delayTime = 60);

    void init();

    void buttonPressed();

    void checkForTime();
};

#endif
