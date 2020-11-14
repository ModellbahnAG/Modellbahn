#include <Arduino.h>
#include <Servo.h>
#include "Wire.h"

#include "NeoPixel.h"


#define LED_PIN         9
#define NUMPIXELS       2

NeoPixel flashLED = NeoPixel(NUMPIXELS, 9);

byte address = 0;

byte servoPin = 8;
byte smoker = 13;
byte alarmLED = 10;

Servo myServo;



void flash() {
    unsigned long startTime = millis();

    while(millis() < startTime + 1000) {
      int led = random(0, 2);

      Serial.print("LED ");
      Serial.println(led);

      flashLED.setColor(led, 255,200,255);

      int delayTime = random(10, 100);
      Serial.println(delayTime);
      delay(delayTime);

      flashLED.off();
    }

    for (int led = 0; led < NUMPIXELS; led++) {
      flashLED.off();
    }
}


void explosion() {
  digitalWrite(smoker, HIGH);
  unsigned long startTime = millis();

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
  digitalWrite(smoker, LOW);
  digitalWrite(13, LOW);
}


void receiveEvent(int howMany) {
  explosion();
}


void setup() {
  Serial.begin(9600);
  pinMode(smoker, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Wire.begin(address);
  Wire.onReceive(receiveEvent);


  digitalWrite(smoker, HIGH);
  delay(20000);
  digitalWrite(smoker, LOW);
}


void loop() {}
