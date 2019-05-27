/*
 * IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to ESP8266 pin 0.
 * Version 0.1 June, 2015
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009, Copyright 2009 Ken Shirriff, http://arcfn.com
 */

#include <IRremoteESP8266.h>

IRsend irsend(D5); //an IR led is connected to GPIO pin 0

void setup()
{
  irsend.begin();
  Serial.begin(9600);
}

void loop() {
  Serial.println("NEC VolUp");
  irsend.sendNEC(0x2FD58A7, 32);
  delay(1000);
  Serial.println("Sony VolUp");
  irsend.sendSony(0x240C, 15);
  delay(1000);
}
