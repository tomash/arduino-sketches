#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <IRremoteESP8266.h>

ESP8266WebServer server(80);
//See more at: http://www.esp8266.com/viewtopic.php?f=29&t=2153#sthash.2kVqu5QF.dpuf

const char* ssid = "REDACTED SSID";
const char* password = "REDACTED PASSWORD";

//int irLedPin = 16; // initialize digital pin 13 as an output.
int irLedPin = 14; // D5 = 14, this is where IR blaster LED is connected
IRsend irsend(14); //an IR led is connected to GPIO pin 0

void setup() {
  Serial.begin(115200);
  delay(10);
  
  pinMode(irLedPin, OUTPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  server.on("/", [](){
    server.send(200, "text/plain", "This is an index page. Hello TRUG!");
  }); 

  server.on("/led", []() {
    String state=server.arg("state"); // ?state=on
    if (state == "on")
      digitalWrite(irLedPin, HIGH);
    else if (state == "off")
      digitalWrite(irLedPin, LOW);
    server.send(200, "text/plain", "Led is now " + state);
  });

  // Start the server 
  server.begin();
  Serial.println("HTTP server started");

  irsend.begin();
  Serial.println("IRSend started");
}

// the loop function runs over and over again forever
void loop() {
  // check for incomming client connections frequently in the main loop:
  server.handleClient();
}
