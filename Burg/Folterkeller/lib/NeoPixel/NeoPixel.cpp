#include <Arduino.h>
#include <NeoPixel.h>

NeoPixel::NeoPixel(byte pin, int number) {
  this -> pin = pin;
  this -> number = number;
  init();
}

void NeoPixel::init() {
  Adafruit_NeoPixel pixels = Adafruit_NeoPixel(number, pin, NEO_GRB + NEO_KHZ800);
  this -> pixels = pixels;
  pixels.begin();
}


void NeoPixel::setColor(byte pixel, int r, int g, int b) {
  pixels.setPixelColor(pixel, r, g, b);
  pixels.show();
}


void NeoPixel::setColor(byte pixel, color color) {
  uint32_t colorValue;
  switch (color) {
    case RED:
      colorValue = pixels.Color(255, 0, 0);
    case GREEN:
      colorValue = pixels.Color(0, 255, 0);
    case YELLOW:
      colorValue = pixels.Color(255, 255, 0);
    case BLUE:
      colorValue = pixels.Color(0, 0, 255);
  }

  pixels.setPixelColor(pixel, colorValue);
  pixels.show();
}


// void NeoPixel::setColor(Adafruit_NeoPixel.Color color) {
//   pixels.setPixelColor(pixel, color);
//   pixels.show();
// }


void NeoPixel::setColor(int r, int g, int b) {
  pixels.fill(r, g, b);
  pixels.show();
}


void NeoPixel::setColor(color color) {
  uint32_t colorValue;
  switch (color) {
    case RED:
      colorValue = pixels.Color(255, 0, 0);
    case GREEN:
      colorValue = pixels.Color(0, 255, 0);
    case YELLOW:
      colorValue = pixels.Color(255, 255, 0);
    case BLUE:
      colorValue = pixels.Color(0, 0, 255);
  }

  pixels.fill(colorValue);
  pixels.show();
}

// void NeoPixel::setColor(Adafruit_NeoPixel.Color color) {
//   pixels.fill(color);
//   pixels.show();
// }



void NeoPixel::off() {
  pixels.clear();
  pixels.show();
}

byte NeoPixel::getPin() {
  return pin;
}
