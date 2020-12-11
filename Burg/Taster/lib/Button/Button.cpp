#include <Button.h>



Button::Button(byte inputPin, byte lightPin, int delayTime = 60) {
  this->inputPin = inputPin;
  this->lightPin = lightPin;
  this->delayTime = delayTime;

  init();
}

void Button::init() {
  pinMode(inputPin, INPUT_PULLUP);
  pinMode(lightPin, OUTPUT);

  digitalWrite(lightPin, LOW);
}

int Button::buttonPressed() {
  Serial.print("b");
  if (this->activated) {
    Serial.println("is activated");
    this->lastPress = millis();

    this->activated = false;
    digitalWrite(lightPin, LOW);

    return callback.invoke();
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
    Serial.println(buttonPressed());
  }
}
