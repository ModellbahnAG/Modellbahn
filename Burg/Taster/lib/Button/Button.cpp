#include <Button.h>


Button::Button(byte address, byte inputPin, byte lightPin, int delayTime = 60) {
  this->address = address;
  this->inputPin = inputPin;
  this->lightPin = lightPin;
  this->delayTime = delayTime;

  init();
}

void Button::init() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(lightPin, OUTPUT);

  digitalWrite(lightPin, HIGH);
}

void Button::handleButton() {
  checkForTime();
  if (!digitalRead(this->inputPin)) {
    buttonPressed();
  }
}

void Button::buttonPressed() {
  if (this->activated) {
    this->lastPress = millis();

    Wire.beginTransmission(this->address);
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
