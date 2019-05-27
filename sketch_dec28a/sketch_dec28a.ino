int outputpin = 14; // D5 = 14

void setup() { 
  pinMode(outputpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(outputpin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(outputpin, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait for a second
}
