#include <Arduino.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "NeoPixel.h"

#define LED_PIN         9
#define NUMPIXELS       2

// Adafruit_NeoPixel flashLED = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
NeoPixel flashLED = NeoPixel(NUMPIXELS, 9);


int taster = 2;

int servoPin = 8;

int rauchgenerator = 13;

int alarmLED = 10;


Servo myServo;

void flash() {
    unsigned long startTime = millis();

    while(millis() < startTime + 1000) {
      int led = random(0, 2);

      Serial.print("LED ");
      Serial.println(led);

      flashLED.setColor(led, flashLED.Color(255,200,255));
      flashLED.show();

      int delayTime = random(10, 100);
      Serial.println(delayTime);
      delay(delayTime);

      flashLED.setPixelColor(led, flashLED.Color(0,0,0));
    }

    for (int led = 0; led < NUMPIXELS; led++) {
      flashLED.setPixelColor(led, flashLED.Color(0,0,0));
    }
}


void explosion() {
  digitalWrite(rauchgenerator, HIGH);
  unsigned long startTime = millis();
  // delayMicroseconds(100000);

  while (millis() < startTime + 5000) {
    digitalWrite(alarmLED, HIGH);
    delay(500);
    digitalWrite(alarmLED, LOW);
    delay(500);
  }
  digitalWrite(alarmLED, LOW);

  myServo.write(90);

  flash();

  delay(5000);
  myServo.write(0);
  digitalWrite(rauchgenerator, LOW);
  digitalWrite(13, LOW);
}


void setup() {
  Serial.begin(9600);
  pinMode(taster, INPUT);
  pinMode(rauchgenerator, OUTPUT);

  // attachInterrupt(0, explosion, RISING);

  myServo.attach(servoPin);
  myServo.write(0);

  flashLED.begin();

  digitalWrite(rauchgenerator, HIGH);
  delay(20000);
  digitalWrite(rauchgenerator, LOW);
}


void loop() {
  if (digitalRead(taster) == HIGH){
    explosion();
  } /*else if (millis()%60000 == 0) {
    digitalWrite(rauchgenerator, HIGH);
  } else if (millis()%20000 == 0 && millis()%60000 != 0) {
    digitalWrite(rauchgenerator, LOW);
  }*/
}
