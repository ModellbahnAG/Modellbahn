#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "Modellbahn.h"

// Position in der die Rauchkammer geöffnet ist
#define SERVO_OPEN 90
// Position in der die Rauchkammer geschlossen ist
#define SERVO_CLOSED 0

// Zeit die der Rauchgenerator Rauch produziert
#define HEATING_TIME 9000

// Pin der LEDs die den Blitz erzeugen
#define FLASH_PIN 9
// Anzahl der LEDs die den Blitz erzeugen
#define NUMPIXELS 2

// Pin an den der Servo der Rauchkammer angeschlossen ist
#define SERVO_PIN 8
// Pin an den der Rauchgenerator angeschlossen ist
#define SMOKER_PIN 13
//Pin an den die Alarm LEDs angeschlossen sind
#define ALARM_LED_PIN 10

// Helligkeit der LEDs für die Beleuchtung
#define EXPLOSION_LIGHTING_BRIGHTNESS 10
// Zeit die die Beleuchtung nachleuchtet
#define GLIMMING_TIME 2000

// Intervall in dem die Alarm LEDs ein- und ausgeschaltet werden
#define ALARM_LED_INTERVAL 500

// Adresse des Arduinos für die I2C Kommunikation mit dem Taster Arduino
#define ADDRESS 0

NeoPixel flashLED = NeoPixel(NUMPIXELS, FLASH_PIN);
Servo myServo;

bool shouldExplode = false;


// Simuliere die Showsprengung
void explosion() {
  // schalte Beleuchtung der Showsprengung an
  flashLED.fill(CRGB::White);
  flashLED.setBrightness(EXPLOSION_LIGHTING_BRIGHTNESS);

  // Rauch produzieren
  digitalWrite(SMOKER_PIN, HIGH);
  unsigned long startTime = millis();

  // während der Rauchgenerator läuft einen Alarm abspielen
  while (millis() < startTime + HEATING_TIME) {
    digitalWrite(ALARM_LED_PIN, !digitalRead(ALARM_LED_PIN));
    delay(ALARM_LED_INTERVAL);
  }
  digitalWrite(ALARM_LED_PIN, LOW);

  // Rauch aus der Rauchkammer rauslassen
  myServo.write(SERVO_OPEN);

  flashLED.flash();
  digitalWrite(SMOKER_PIN, LOW);

  // für eine Zeit Beleuchtung aktiv lassen
  flashLED.fill(CRGB::White);
  flashLED.setBrightness(EXPLOSION_LIGHTING_BRIGHTNESS);
  delay(GLIMMING_TIME);
  myServo.write(SERVO_CLOSED);
  flashLED.off();
}


/* Setze shouldExplode auf true wenn eine Signal vom Taster Arduino ankommt
*
* Die eigentlich Explosion kann nicht in dieser Funktion ausgeführt werden, da
* es bei Interrupt Funktionen Probleme mit delay gibt.
*/
void receiveEvent(int howMany) {
  shouldExplode = Wire.read();
}


void setup() {
  Serial.begin(9600);

  pinMode(SMOKER_PIN, OUTPUT);
  pinMode(ALARM_LED_PIN, OUTPUT);

  myServo.attach(SERVO_PIN);
  myServo.write(SERVO_CLOSED);

//starte die I2C Kommunikation mit dem Taster Arduino
  Wire.begin(ADDRESS);
  Wire.onReceive(receiveEvent);
}


void loop() {
  // Überprüfe, ob Explosion stattfinden soll und evtl starten
  if (shouldExplode) {
    explosion();
    shouldExplode = false;
  }
}
