int taster = 12;
int bahn = 13;
int bahn1 = 10;
int bahn2 = 9;
int led = 11;

int helligkeitLed = 50;

void setup() {
  pinMode(taster, INPUT);
  pinMode(bahn, OUTPUT);
  pinMode(bahn1, OUTPUT);
  pinMode(bahn2, OUTPUT);
  pinMode(led, OUTPUT);

  randomSeed(analogRead(A0));
  Serial.begin(9600);

  analogWrite(led, helligkeitLed);
}

void loop() {
  int zufall = random(1, 10000);

  if (zufall == 1) {
    analogWrite(led, 0);
    delay(5);
    analogWrite(led, helligkeitLed);
  }

  if (digitalRead(taster)) {
    digitalWrite(bahn, HIGH);
    digitalWrite(bahn1, HIGH);
    digitalWrite(bahn2, HIGH);
    delay(5000);
    digitalWrite(bahn, LOW);
    digitalWrite(bahn1, LOW);
    digitalWrite(bahn2, LOW);
  }
}
