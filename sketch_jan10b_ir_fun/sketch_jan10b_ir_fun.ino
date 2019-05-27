#include <IRremoteESP8266.h>

//int irLedPin = 16; // initialize digital pin 13 as an output.
int irLedPin = D5; 
IRsend irsend(D5); //an IR led is connected to GPIO pin 0
int khz = 38; // 38kHz carrier frequency for the NEC protocol

// Toshiba TV is NEC1 protocol
// discrete codes are at http://www.remotecentral.com/cgi-bin/mboard/rc-discrete/thread.cgi?6824


// Protocol NEC1, device 64, OBC 26
// Toshiba TVs: Protocol NEC1 device 64 subdevice -1 Get codes
// http://irdb.tk/

void setup() {
   irsend.begin();

   //pinMode(irLedPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // send volume+
  irsend.sendNEC(26, 68);
  
  // wait 1s
  delay(200);

  //digitalWrite(irLedPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(500);              // wait for a second
  //digitalWrite(irLedPin, LOW);    // turn the LED off by making the voltage LOW
  //delay(500);              // wait for a second
}
