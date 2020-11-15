#ifndef MY_NEOPIXEL_H
#define MY_NEOPIXEL_H

#include <Adafruit_NeoPixel.h>

enum color {
  RED,
  GREEN,
  YELLOW,
  BLUE
};

class NeoPixel {
  private:
    byte pin;
    int number;
    Adafruit_NeoPixel pixels;

  public:
    NeoPixel(byte pin, int number);
    void init();

    void setColor(byte pixel, int r, int g, int b);
    void setColor(byte pixel, color color);
    // void setColor(byte pixel, Adafruit_NeoPixel.Color color);

    void setColor(int r, int g, int b);
    void setColor(color color);
    // void setColor(Adafruit_NeoPixel.Color color);

    void off();

    byte getPin();
};

#endif
