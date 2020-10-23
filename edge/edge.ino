// this constant won't change:
const int  buttonPin = 2;
const int ledPin = 13;

// Variables will change:
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.println("rising edge");
    } else {
      Serial.println("falling edge");
    }
    delay(50);
    if (buttonPushCounter % 2 == 0) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
  lastButtonState = buttonState;  
}
