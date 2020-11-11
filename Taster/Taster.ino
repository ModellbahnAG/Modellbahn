//Taster Pin
int taster[] = {53};
//Taster LED Pin
int tasterLED[] = {51};

//Ausgänge
int ausgang[] = {52};

//Zeit, die die Taster deaktiviert sein sollen (in Sekunden)
int warten[] = {20};

//Zeit, wann der Taster das letze Mal gedrückt wurde
unsigned long zeit[] = {0};

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 1; i++) {
    Serial.println(i);
    pinMode(taster[i], INPUT_PULLUP);
    pinMode(tasterLED[i], OUTPUT);
    pinMode(ausgang[i], OUTPUT);


    digitalWrite(tasterLED[i], HIGH);

    warten[i] = warten[i] * 1000;
  }
}

void loop() {
  for (int i = 0; i < 1; i++) {
    Serial.print("LED: ");
    Serial.println(i);
    if (millis() > zeit[i] + warten[i]) {
      digitalWrite(tasterLED[i], HIGH);
    }
  }

  for (int i = 0; i < 1; i++) {
    Serial.print("Taster: ");
    Serial.println(i);
    if (!digitalRead(taster[i])) {
      Serial.println("Taster gedrückt");
      if (millis() > zeit[i] + warten[i]) {
        zeit[i] = millis();
        digitalWrite(ausgang[i], HIGH);
        digitalWrite(tasterLED[i], LOW);
        delay(500);
        digitalWrite(ausgang[i], LOW);
      }
    }
  }
}
