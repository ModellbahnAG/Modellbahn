#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "Modellbahn.h"


#define PIN         9
#define NUMPIXELS   2
#define ADDRESS 0

NeoPixel flashLED = NeoPixel(NUMPIXELS, PIN);


byte servoPin = 8;
byte smoker = 13;
byte alarmLED = 10;

Servo myServo;

bool shouldExplode = false;


void explosion() {
  digitalWrite(smoker, HIGH);
  unsigned long startTime = millis();

  while (millis() < startTime + 10000) {
    digitalWrite(alarmLED, !digitalRead(alarmLED));   //alle 0.5 Sekunden den Wert der LED wechseln
    delay(500);
  }

  digitalWrite(alarmLED, LOW);
  digitalWrite(smoker, LOW);

  myServo.write(90);

  LightEffects::flash(&flashLED);
  flashLED.off();

  delay(2000);
  myServo.write(0);
}


void receiveEvent(int howMany) {
  shouldExplode = Wire.read();
}


void setup() {
  Serial.begin(9600);

  pinMode(smoker, OUTPUT);
  pinMode(alarmLED, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);
}


void loop() {
  if (shouldExplode) {
    explosion();
    shouldExplode = false;
  }
}
