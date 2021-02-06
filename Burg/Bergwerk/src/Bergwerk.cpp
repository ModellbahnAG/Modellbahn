#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "Modellbahn.h"

#define SERVO_OPEN 90
#define SERVO_CLOSED 0

#define HEATING_TIME 9000

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
  flashLED.fill(CRGB::White);
  flashLED.setBrightness(10);

  digitalWrite(smoker, HIGH);
  unsigned long startTime = millis();

  while (millis() < startTime + HEATING_TIME) {
    digitalWrite(alarmLED, !digitalRead(alarmLED));   //alle 0.5 Sekunden den Wert der LED wechseln
    delay(500);
  }

  digitalWrite(alarmLED, LOW);

  myServo.write(SERVO_OPEN);

  flashLED.flash();
  digitalWrite(smoker, LOW);

  flashLED.fill(CRGB::White);
  flashLED.setBrightness(10);


  delay(2000);
  myServo.write(SERVO_CLOSED);
  flashLED.off();
}


void receiveEvent(int howMany) {
  shouldExplode = Wire.read();
}


void setup() {
  Serial.begin(9600);

  pinMode(smoker, OUTPUT);
  pinMode(alarmLED, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(SERVO_CLOSED);

  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);
}


void loop() {
  if (shouldExplode) {
    explosion();
    shouldExplode = false;
  }
}
