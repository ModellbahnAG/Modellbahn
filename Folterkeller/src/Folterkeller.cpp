#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//Auskommentieren um Serielle Komunikation abzuschalten (Ausgabe der Werte auf den Computer)
//#define debug

//PIn für die LED
#define LEDPIN 11

//How many LEDs
#define NUMPIXELS 4

int taster = 10;

int fire = 8;
int light = 9;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);

void setPixelBrightness(int pixel, unsigned long red, unsigned long green, unsigned long blue, unsigned long brightness) {
  unsigned long redBrightness = red * brightness / 255;
  unsigned long greenBrightness = green * brightness / 255;
  unsigned long blueBrightness = blue * brightness / 255;

  pixels.setPixelColor(pixel, pixels.Color(redBrightness, greenBrightness, blueBrightness));

  pixels.show();

#ifdef debug
  Serial.print("Pixel ");
  Serial.println(pixel);

  Serial.print("Rot: ");
  Serial.println(redBrightness);
  Serial.print("Gruen: ");
  Serial.println(greenBrightness);
  Serial.print("Blau: ");
  Serial.println(blueBrightness);

  Serial.println();
#endif
}

//-------------------------------------------------------------------------------------------------------------------------

void fackel() {
  int pixel = random(0, 4);
  setPixelBrightness(pixel, 255, 50, 0, 100);
  delay(random(10, 100));
  setPixelBrightness(pixel, 255, 50, 0, 255);
}

//-------------------------------------------------------------------------------------------------------------------------

void setup() {
#ifdef debug
  Serial.begin(9600);
#endif

  pinMode(taster, INPUT);

  pinMode(light, OUTPUT);
  pinMode(fire, OUTPUT);

  pixels.begin();

  for (int i = 0; i < NUMPIXELS; i++) {
    setPixelBrightness(i, 0, 0, 0, 0);
  }
  Serial.println("serial");
}

//-------------------------------------------------------------------------------------------------------------------------

void loop() {
  Serial.println(digitalRead(taster));
  if (digitalRead(taster) == HIGH) {
    unsigned long timeEnd = millis() + 30000;

    digitalWrite(fire, HIGH);
    analogWrite(light, 50);


    while (millis() < timeEnd) {
      fackel();
    }
    for (int i = 0; i < NUMPIXELS; i++) {
      setPixelBrightness(i, 0, 0, 0, 0);
    }
    digitalWrite(fire, LOW);
    digitalWrite(light, LOW);
  }
}



//-------------------------------------------------------------------------------------------------------------------------
