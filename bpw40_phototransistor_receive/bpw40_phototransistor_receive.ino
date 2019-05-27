int phototran = A0; // ADC
int photodig  = D1; // digital input
int interval = 100; //miliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(photodig, INPUT);
  pinMode(phototran, INPUT);

  Serial.begin(115200);        //inicjalizacja monitora szeregowego
  Serial.println("Phototransistor test");
}

void loop() {
  // put your main code here, to run repeatedly:

  int lightval = analogRead(phototran);
  int digval = digitalRead(photodig);
  Serial.print(digval);
  Serial.print(" digital, analog A0: ");
  Serial.println(lightval);
  delay(interval);
  
}
