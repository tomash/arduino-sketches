/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 Sept, 2015
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009, Copyright 2009 Ken Shirriff, http://arcfn.com
 */

#include <IRremoteESP8266.h>

int RECV_PIN = D7; //an IR detector/demodulatord is connected to GPIO pin D7

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

/*
 * Toshiba TV remote:
 * 32 bits length
 * e.g. irsend.sendNEC(0x2FD58A7, 32);
 * vol+ : 2FD58A7
 * vol- : 2FD7887
 * mute : 2FD08F7
 * prog+: 2FDD827
 * prog-: 2FDF807
 * input: 2FD28D7
 * up     2FD9867
 * down   2FDB847
 * left   2FD42BD
 * right  2FD02FD
 * ok     2FD847B
 * red    2FD12ED
 * green  2FD926D
 * yellow 2FD52AD
 * blue   2FDD22D
 * power  2FD48B7
 * back   2FD26D9
 * exit   2FDC23D
 * 
 * 
 * Samsung Bluray Remote
 * power: E4CD1208
 * apps:  93E41944
 * home:  11DB53E4
 * up:    D04CFC60
 * down:  61DB14E2
 * left:  72726A46
 * right: 6F89644
 * enter: 20464B24
 * 
 * Sony soundbar
 * power: 540C (and some garbage)
 * vol+: 240C
 * vol-: 640C
 * input: 4B0D
 * 
 * 
 */
