#include <Button.h>


Button *pointerToClass;

static void outsideInterruptHandler() {
  pointerToClass->buttonPressed();
}


Button::Button(byte address, byte inputPin, byte lightPin, int delayTime = 60) {
  this->address = address;
  this->inputPin = inputPin;
  this->lightPin = lightPin;
  this->delayTime = delayTime;

  init();
}

void Button::init() {
  pointerToClass = this;

  pinMode(inputPin, INPUT_PULLUP);
  pinMode(lightPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(inputPin), outsideInterruptHandler, RISING);

  digitalWrite(lightPin, HIGH);
}

void Button::buttonPressed() {
  if (this->activated) {
    this->lastPress = millis();

    Wire.beginTransmission(address);
    Wire.write(1);
    Wire.endTransmission();

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
