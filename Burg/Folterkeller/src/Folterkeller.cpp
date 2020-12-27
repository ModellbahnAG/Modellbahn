#include <Arduino.h>
#include <Wire.h>
#include "NeoPixel.h"


//PIn für die LED
#define LEDPIN 11

//How many LEDs
#define NUMPIXELS 4


byte address = 1;


int fire = 8;
int light = 9;

NeoPixel pixels(NUMPIXELS, LEDPIN);


// Funktion zum einfachen Anpassen der Helligkeit bei gleichbleibender Farbe
void setPixelBrightness(int pixel, unsigned long red, unsigned long green, unsigned long blue, unsigned long brightness) {
  unsigned long redBrightness = red * brightness / 255;
  unsigned long greenBrightness = green * brightness / 255;
  unsigned long blueBrightness = blue * brightness / 255;

  pixels.setColor(pixel, redBrightness, greenBrightness, blueBrightness);


}


void fackel() {
  int pixel = random(0, 4);
  setPixelBrightness(pixel, 255, 50, 0, 100);
  delay(random(10, 100));
  setPixelBrightness(pixel, 255, 50, 0, 255);
}


void receiveEvent(int howMany) {
  unsigned long timeEnd = millis() + 30000;

  digitalWrite(fire, HIGH);
  analogWrite(light, 50);

  while (millis() < timeEnd) {
    fackel();
  }
  pixels.off();
  digitalWrite(fire, LOW);
  digitalWrite(light, LOW);
}


void setup() {
  Wire.begin(address);
  Wire.onReceive(receiveEvent);

  pinMode(light, OUTPUT);
  pinMode(fire, OUTPUT);

  pixels.off();
  receiveEvent(0);
}

void loop() {}
