#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "Modellbahn.h"

#define SERVO_OPEN 90
#define SERVO_CLOSED 0

#define HEATING_TIME 9000

#define FLASH_PIN 9
#define NUMPIXELS 2

#define SERVO_PIN 8
#define SMOKER_PIN 13
#define ALARM_LED_PIN 10

#define EXPLOSION_LIGHTING_BRIGHTNESS 10
#define GLIMMING_TIME 2000

#define ADDRESS 0

NeoPixel flashLED = NeoPixel(NUMPIXELS, FLASH_PIN);


Servo myServo;

bool shouldExplode = false;


void explosion() {
  flashLED.fill(CRGB::White);
  flashLED.setBrightness(EXPLOSION_LIGHTING_BRIGHTNESS);

  digitalWrite(SMOKER_PIN, HIGH);
  unsigned long startTime = millis();

  while (millis() < startTime + HEATING_TIME) {
    digitalWrite(ALARM_LED_PIN, !digitalRead(ALARM_LED_PIN));   //alle 0.5 Sekunden den Wert der LED wechseln
    delay(500);
  }

  digitalWrite(ALARM_LED_PIN, LOW);

  myServo.write(SERVO_OPEN);

  flashLED.flash();
  digitalWrite(SMOKER_PIN, LOW);

  flashLED.fill(CRGB::White);
  flashLED.setBrightness(EXPLOSION_LIGHTING_BRIGHTNESS);

  delay(GLIMMING_TIME);

  myServo.write(SERVO_CLOSED);
  flashLED.off();
}


void receiveEvent(int howMany) {
  shouldExplode = Wire.read();
}


void setup() {
  Serial.begin(9600);

  pinMode(SMOKER_PIN, OUTPUT);
  pinMode(ALARM_LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
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
