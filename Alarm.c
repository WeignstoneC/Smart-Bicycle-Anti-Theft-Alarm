int ledPin = 13;
int inputPin = 8;
int piezoPin = 9;
int val = 0;
int pirState = LOW; // <--- It MUST be here!

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);
  
  if (val == HIGH) { // Motion detected (PIR output is HIGH)
    digitalWrite(ledPin, HIGH);
    tone(piezoPin, 1000, 500);

    if (pirState == LOW) { // Check if this is a NEW detection
      Serial.println("Ada pergerakan!");
      pirState = HIGH;      // Set state to HIGH (so we don't print again)
    }
  } else { // No motion (PIR output is LOW)
    digitalWrite(ledPin, LOW);

    if(pirState == HIGH) { // Check if motion just STOPPED
      Serial.println("Tiada Pergerakan");
      pirState = LOW;       // Set state back to LOW
    }
  }
}
