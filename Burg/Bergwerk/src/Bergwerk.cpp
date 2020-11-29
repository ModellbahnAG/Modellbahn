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

bool shouldExplode = false;


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

  while (millis() < startTime + 10000) {
    digitalWrite(alarmLED, !digitalRead(alarmLED));   //alle 0.5 Sekunden den Wert der LED wechseln
    delay(500);
  }

  digitalWrite(alarmLED, LOW);
  digitalWrite(smoker, LOW);

  myServo.write(90);

  flash();

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

  Wire.begin(address);
  Wire.onReceive(receiveEvent);
}


void loop() {
  if (shouldExplode) {
    explosion();
    shouldExplode = false;
  }
}
