int ledpin = 4;
int phototran = A0; // ADC
int interval = 100; //miliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  pinMode(phototran, INPUT);

  Serial.begin(115200);        //inicjalizacja monitora szeregowego
  Serial.println("Test fototranzystora");
}

void loop() {
  // put your main code here, to run repeatedly:

  int lightval = analogRead(phototran);
  Serial.println(lightval);
  delay(interval);
  
}
