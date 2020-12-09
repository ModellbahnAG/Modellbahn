#include "Button.h"


Button *pointerToClass;

static void outsideInterruptHandler() {
  pointerToClass->buttonPressed();
}


Button::Button(byte inputPin, byte lightPin, int delayTime = 60) {
  this->inputPin = inputPin;
  this->lightPin = lightPin;
  this->delayTime = delayTime;

  init();
}

void Button::init() {
  pointerToClass = this;

  pinMode(inputPin, INPUT_PULLUP);
  pinMode(lightPin, OUTPUT);

  digitalWrite(lightPin, LOW);
}

void Button::buttonPressed() {
  if (this->activated) {
    this->lastPress = millis();

    buttonPressCallback(this->variable);

    this->activated = false;
    digitalWrite(lightPin, LOW);
  }
}

void Button::checkForTime() {
  if (millis() >= this->lastPress + delayTime * 1000) {
    this->activated = true;
    digitalWrite(lightPin, HIGH);
  }
}

void Button::handleButton() {
  checkForTime();
  if (!digitalRead(this->inputPin)) {
    buttonPressed();
  }
}
