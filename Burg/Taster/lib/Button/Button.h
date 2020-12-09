#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include <Wire.h>


class Button {
  private:
    byte inputPin;    // Pin des Tasters
    byte lightPin;    // Pin des Lichts
    int delayTime;    // Zeit, die der Taster deaktiviert ist (in Sekunden)

    unsigned long lastPress = 0;   // Zeit, zu der der Taster zum letzten Mal gedrückt wurde
    bool activated = true;

    byte variable;      //TODO: variable optional machen und verschiedene Typen einsetzen
    void (*buttonPressCallback)(byte);  // vom Nutzer übergebene Funktion, die ausgeführt wird sobald der Taster gedrückt wurde


  public:
    Button(byte inputPin, byte lightPin, int delayTime = 60);
    void init();

    // Der Nutzer übergibt hier eine parameterlose Funktion, die ausgeführt wird, sobald der Taster gedrückt wurde
    void setCallback(void (*buttonPressCallbackUsr)(byte), byte variable) {
      this->variable = variable;
      this->buttonPressCallback = buttonPressCallbackUsr;
    }

    void buttonPressed();
    void checkForTime();
    void handleButton();

};

#endif
