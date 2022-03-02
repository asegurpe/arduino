int pins[] = {LED_BUILTIN, 6, 5, 4, 3};

long interval[][2] = {{1000000L, 1000000L}, {1000L, 1000L}, {150L, 150L}, {50L, 150L}, {40L, 40L}};
long previousMicros[] = {0, 0, 0, 0, 0};
int outStatus[] = {LOW, LOW, LOW, LOW, LOW};

long previousTickle = 0L;
long intervalTickle = 200L;

void setup() {
  Serial.begin(115200);
  for (int thisPin = 0; thisPin < sizeof(pins) / sizeof(int); thisPin++) {
    previousMicros[thisPin] = micros();
    pinMode(pins[thisPin], OUTPUT);
    digitalWrite(pins[thisPin], LOW);
  }
  previousTickle = micros();
}

void loop() {
  unsigned long currentMicros = micros();
  if (outStatus[1] == LOW && currentMicros - previousTickle > intervalTickle) {
    previousTickle = currentMicros;
    digitalWrite(pins[1], HIGH);
    digitalWrite(pins[1], LOW);
  }
  for (int thisPin = 0; thisPin < sizeof(pins) / sizeof(int); thisPin++) {
    process(thisPin, currentMicros); 
  }
}

void process(int thisPin, unsigned long currentMicros) {
  if (outStatus[thisPin] == LOW && currentMicros - previousMicros[thisPin] > interval[thisPin][0]) {
    if (thisPin == 0) {
      Serial.println("ON");
    }
    previousMicros[thisPin] = currentMicros;
    outStatus[thisPin] = HIGH;
    digitalWrite(pins[thisPin], outStatus[thisPin]);
  } else if (outStatus[thisPin] == HIGH && currentMicros - previousMicros[thisPin] > interval[thisPin][1]) {
    if (thisPin == 0) {
      Serial.println("OFF");
    }
    previousMicros[thisPin] = currentMicros;
    outStatus[thisPin] = LOW;
    digitalWrite(pins[thisPin], outStatus[thisPin]);
  }
}
